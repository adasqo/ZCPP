#pragma once

#include "activation_layer.hpp"

class ReLU : public ActivationLayer
{
    private:
        float actv_point;
        float coeff;
        virtual float calculate_result(float) override;
        virtual float calculate_derivative(float) override;
    public:
        ReLU();
        ReLU(int);
        void set_actv_point(float);
        void set_coeff(float);
        std::string return_information() override;
};
