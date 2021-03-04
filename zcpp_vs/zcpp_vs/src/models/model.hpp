#pragma once
#include "../layers/dense.hpp"
#include <list>
class Model
{
    private:
        Matrix<float> propagate_forward(Matrix<float>);
        void propagate_backward(Matrix<float>);
        float perform_batch_calculations(std::list<Matrix<float>>, std::list<Matrix<float>>);
    protected:
        std::list<Layer*> layers;
    public:
        Model();
        virtual void add(Layer&);
        // virtual void compile();
        void train(int, int, std::list<Matrix<float>>, std::list<Matrix<float>>);
};
