#pragma once
#include "../layers/dense.hpp"
#include <list>
class Model
{
    private:
        virtual Matrix<float> propagate_forward(Matrix<float>) = 0;
        virtual void propagate_backward(float, Matrix<float>) = 0;
        virtual float perform_batch_calculations(float, std::list<Matrix<float>>, std::list<Matrix<float>>) = 0;
    protected:
        std::list<Layer*> layers;
        float calculate_error(Matrix<float> output, Matrix<float> expected);
    public:
        Model();
        virtual void add(Layer&) = 0;
        virtual void train(int, int, float, std::list<Matrix<float>>, std::list<Matrix<float>>) = 0;
};
