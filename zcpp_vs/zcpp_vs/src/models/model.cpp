#include "model.hpp"
#include <iostream>

Model::Model()
{
    layers = std::list<Layer*>();
};
void Model::add(Layer& layer)
{
    layers.push_back(&layer);
};
// virtual void compile();
void Model::train()
{
    propagate_forward();
};
void Model::propagate_forward()
{
    std::list<Layer*>::iterator it;
    for (it = layers.begin(); it != layers.end(); ++it)
    {
        std::cout << "test";
        /*Matrix<float> m = (*it)->perform_calculations(Matrix<float>());*/
    }
};
