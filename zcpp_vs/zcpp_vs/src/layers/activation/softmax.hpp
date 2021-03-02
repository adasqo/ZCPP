#pragma once

#include "activation_layer.hpp"

class Softmax : public ActivationLayer
{
    private:    
        float beta;
    public:
        Softmax();
        Softmax(int);
        Matrix<float> transfer_result(Matrix<float>);
        Matrix<float> transfer_derivative(Matrix<float>);
        void set_beta(float);
};
