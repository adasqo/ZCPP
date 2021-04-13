#pragma once

#include "activation_layer.hpp"

class Sigmoid : public ActivationLayer
{
    private:
        float beta;
        float calculate_result(float) override;
        float calculate_derivative(float) override;
    public:
        Sigmoid();
        Sigmoid(int);
        void set_beta(float);
        std::string return_information() override;
};
