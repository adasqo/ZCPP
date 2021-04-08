#pragma once
#include "../layers/dense.hpp"
#include <list>
class Model
{
    private:
        virtual Matrix<float> propagate_forward(Matrix<float>);
        virtual void propagate_backward(float, Matrix<float>);
        virtual float perform_batch_calculations(float, std::list<Matrix<float>>, std::list<Matrix<float>>);
    protected:
        std::list<Layer*> layers;
        float calculate_error(Matrix<float> output, Matrix<float> expected);
    public:
        Model();
        virtual void add(Layer&);
        virtual void train(int, int, float, std::list<Matrix<float>>, std::list<Matrix<float>>);
};
