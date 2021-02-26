#pragma once
#include "../layers/dense.hpp"
#include <list>
class Model
{
    private:
        void propagate_forward(Matrix<float>);
    protected:
        std::list<Layer*> layers;
    public:
        Model();
        virtual void add(Layer&);
        // virtual void compile();
        void train(int, int, Matrix<float>);
};
