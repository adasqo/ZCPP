#pragma once
#include "../layers/dense.hpp"
#include <list>
class Model
{
    private:
        Matrix<float> propagate_forward(Matrix<float>);
        float calculate_loss(Matrix<float>, Matrix<float>);
    protected:
        std::list<Layer*> layers;
    public:
        Model();
        virtual void add(Layer&);
        // virtual void compile();
        void train(int, int, Matrix<float>, Matrix<float>);
};
