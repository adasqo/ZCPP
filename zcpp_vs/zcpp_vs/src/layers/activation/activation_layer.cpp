#pragma once
#include "activation_layer.hpp"


ActivationLayer::ActivationLayer() : Layer() {};
ActivationLayer::ActivationLayer(int incomig_units)
{
	this->incoming_units = incomig_units;
};
Matrix<float> ActivationLayer::perform_calculations_forward(Matrix<float> input)
{
	return transfer_result(input);
};
Matrix<float> ActivationLayer::perform_calculations_backward(Matrix<float> input)
{
	return transfer_derivative(input);
}
Matrix<float> ActivationLayer::transfer_result(Matrix<float> input)
{
    for (int i = 0; i < input.get_rows(); ++i)
        input(i, 0) = calculate_result(input(i, 0));

    return input;
};
Matrix<float> ActivationLayer::transfer_derivative(Matrix<float> input)
{
    for (int i = 0; i < input.get_rows(); ++i)
        input(i, 0) = calculate_derivative(input(i, 0));

    return input;
};