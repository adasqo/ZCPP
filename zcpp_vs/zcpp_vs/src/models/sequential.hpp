#pragma once
#include "../layers/dense.hpp"
#include <list>

class Sequential
{
    private:
        Matrix<float> propagate_forward(Matrix<float>);
        void propagate_backward(Matrix<float>);
        float perform_batch_calculations(std::list<Matrix<float>>, std::list<Matrix<float>>);
        std::tuple<std::list<Matrix<float>>, std::list<Matrix<float>>> shuffle_input(std::list<Matrix<float>>, std::list<Matrix<float>>);
        std::tuple<std::list<Matrix<float>>, std::list<Matrix<float>>> create_batch(std::tuple<std::list<Matrix<float>>, std::list<Matrix<float>>>, int, int);
    protected:
        std::list<Layer*> layers;
    public:
        Sequential();
        virtual void add(Layer&);
        // virtual void compile();
        void train(int, int, std::list<Matrix<float>>, std::list<Matrix<float>>);
};
