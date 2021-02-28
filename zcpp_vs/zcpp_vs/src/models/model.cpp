#include "model.hpp"
#include <iostream>
#include <math.h>

Model::Model()
{
    layers = std::list<Layer*>();
};
void Model::add(Layer& layer)
{
    layers.push_back(&layer);
};
void Model::train(int epochs, int batches, Matrix<float> input, Matrix<float> output)
{
    for (int i = 0; i < epochs; ++i)
    {
        std::cout << "Training epoch: " << i + 1 << std::endl;
        propagate_forward(input);
    }

};
Matrix<float> Model::propagate_forward(Matrix<float> input)
{
    std::list<Layer*>::iterator it;
    for (it = layers.begin(); it != layers.end(); ++it)
        input = (*it)->perform_calculations_forward(input);
    
    return input;
};
float Model::calculate_loss(Matrix<float> input, Matrix<float> output)
{
    float sum = 0;
    for (int i = 0; i < input.get_rows(); ++i)
        sum += input(i, 0) * output(i, 0);
    return -log(sum);
}