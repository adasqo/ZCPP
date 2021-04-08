#include "model.hpp"
#include <iostream>
#include <math.h>

Model::Model()
{
};
float Model::calculate_error(Matrix<float> output, Matrix<float> expected)
{
    return (output.transpose() * expected)(0, 0);
};

Matrix<float> Model::propagate_forward(Matrix<float>) { return Matrix<float>(); };
void Model::propagate_backward(float, Matrix<float>) {};
float Model::perform_batch_calculations(float, std::list<Matrix<float>>, std::list<Matrix<float>>) { return 0; };
void Model::add(Layer&) {};
void Model::train(int, int, float, std::list<Matrix<float>>, std::list<Matrix<float>>) {};