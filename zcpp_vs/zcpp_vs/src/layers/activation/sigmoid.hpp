#pragma once

#include "activation_layer.hpp"

class Sigmoid : public ActivationLayer
{
    private:
        float calculate_result(float) override;
        float calculate_derivative(float) override;
    public:
        Sigmoid();
        Sigmoid(int);
};
