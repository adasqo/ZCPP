#pragma once
#include "activation_layer.hpp"
#include <tuple>

ActivationLayer::ActivationLayer() : Layer() {};
ActivationLayer::ActivationLayer(int incomig_units)
{
	this->incoming_units = incomig_units;
};
Matrix<float> ActivationLayer::perform_calculations_forward(Matrix<float> input)
{
	return transfer_result(input);
};
std::tuple<Matrix<float>, Matrix<float>> ActivationLayer::perform_calculations_backward(std::tuple<Matrix<float>, Matrix<float>> input, float)
{
	return transfer_derivative(std::get<0>(input));
}
Matrix<float> ActivationLayer::transfer_result(Matrix<float> input)
{
    for (int i = 0; i < input.get_rows(); ++i)
        input(i, 0) = calculate_result(input(i, 0));
    result = input;
    //std::cout << result;
    return input;
};
std::tuple<Matrix<float>, Matrix<float>> ActivationLayer::transfer_derivative(Matrix<float> input)
{
    for (int i = 0; i < input.get_rows(); ++i)
        input(i, 0) = calculate_derivative(input(i, 0));

    return std::make_tuple(input, result);
};