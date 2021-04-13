#pragma once
#include "activation_layer.hpp"
#include <tuple>

ActivationLayer::ActivationLayer() : Layer() {};
ActivationLayer::ActivationLayer(int incomig_units): Layer(incomig_units) {};
Matrix<float> ActivationLayer::perform_calculations_forward(Matrix<float> input)
{
	return transfer_result(input);
};
Matrix<float> ActivationLayer::perform_calculations_backward(Matrix<float> input, float)
{
	return transfer_derivative(input);
}
Matrix<float> ActivationLayer::transfer_result(Matrix<float> input)
{
    for (int i = 0; i < input.get_rows(); ++i)
        input(i, 0) = calculate_result(input(i, 0));
    result = input;
    return input;
};
Matrix<float> ActivationLayer::transfer_derivative(Matrix<float> input)
{
    Matrix<float> delta = Matrix<float>(input.get_rows(), 1);
    for (int i = 0; i < delta.get_rows(); i++)
        delta(i, 0) = calculate_derivative(result(i, 0));
    return delta.dot(input);
};