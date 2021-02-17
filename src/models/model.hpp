#pragma once
#include "../layers/layer.hpp"
#include "../layers/dense.hpp"
#include "../matrix/matrix.hpp"
#include <list>
class Model
{
    private:
        void propagate_forward()
        {
            std::list<Layer*>::iterator it;
            for (it = layers.begin(); it != layers.end(); ++it)
            {
                std::cout<<"test";
                Matrix<float> m = (*it)->perform_calculations(Matrix<float>());
            }
        };
    protected:
        std::list<Layer*> layers;
    public:
        Model()
        {
            layers = std::list<Layer*>();
        };
        virtual void add(Layer& layer)
        {
            layers.push_back(&layer);
        };
        // virtual void compile();
        void train()
        {
            propagate_forward();
        };
};
