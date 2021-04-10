#pragma once

#include "activation_layer.hpp"

class Softmax : public ActivationLayer
{
    private:    
        float beta;
        float calculate_result(float) override;
        float calculate_derivative(float) override;
    public:
        Softmax();
        Softmax(int);
        Matrix<float> transfer_result(Matrix<float>) override;
        void set_beta(float);
};
