#pragma once
#include "../layers/dense.hpp"
#include "model.hpp"
#include <list>

class Sequential: Model
{
    private:
        Matrix<float> propagate_forward(Matrix<float>) override;
        void propagate_backward(float, Matrix<float>) override;
        float perform_batch_calculations(float, std::list<Matrix<float>>, std::list<Matrix<float>>) override;
        std::tuple<std::list<Matrix<float>>, std::list<Matrix<float>>> shuffle_input(std::list<Matrix<float>>, std::list<Matrix<float>>);
        std::tuple<std::list<Matrix<float>>, std::list<Matrix<float>>> create_batch(std::tuple<std::list<Matrix<float>>, std::list<Matrix<float>>>, int, int);
        int argmax(Matrix<float>);
    public:
        Sequential();
        virtual void add(Layer&) override;
        void train(int, int, float, std::list<Matrix<float>>, std::list<Matrix<float>>) override;
        
};
