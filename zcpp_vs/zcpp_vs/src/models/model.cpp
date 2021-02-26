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
void Model::train(int epochs, int batches, Matrix<float> input)
{
    for (int i = 0; i < epochs; ++i)
    {
        std::cout << "Training epoch: " << i + 1 << std::endl;
        propagate_forward(input);
    }

};
void Model::propagate_forward(Matrix<float> input)
{
    std::list<Layer*>::iterator it;
    for (it = layers.begin(); it != layers.end(); ++it)
    {
        std::cout << "test";
        Matrix<float> m = (*it)->perform_calculations(input);
        std::cout << m;
    }
};
