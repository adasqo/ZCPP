#pragma once

#include "../layer.hpp"

class ReLU : public Layer
{
    private:
        float actv_point;
        float coeff;
    public:
        ReLU();
        ReLU(int);
        Matrix<float> perform_calculations_forward(Matrix<float>) override;
        void set_actv_point(float);
        void set_coeff(float);
};
