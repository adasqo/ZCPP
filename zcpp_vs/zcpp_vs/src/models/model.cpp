#include "model.hpp"
#include <iostream>
#include <math.h>

Model::Model()
{
    layers = std::list<Layer*>();
};
float Model::calculate_error(Matrix<float> output, Matrix<float> expected)
{
    return (output.transpose() * expected)(0, 0);
};