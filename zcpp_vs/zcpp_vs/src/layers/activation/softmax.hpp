#pragma once

#include "../layer.hpp"

class Softmax : public Layer
{
    private:    
        float beta;
    public:
        Softmax();
        Softmax(int);
        Softmax(int, int);
        Matrix<float> perform_calculations_forward(Matrix<float>) override;
        void set_beta(float);
};
