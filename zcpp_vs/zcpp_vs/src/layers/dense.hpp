#pragma once
#include "layer.hpp"
#include "../matrix/matrix.hpp"

class Dense: public Layer
{
    private:
        Matrix<float> weights;
        Matrix<float> output;
        Matrix<float> delta;
        void initiatie_weights();
        void update_weights(Matrix<float>, float);
    public:
        Dense();
        Dense(int);
        Dense(int, int);

        Matrix<float> perform_calculations_forward(Matrix<float>) override;
        Matrix<float> perform_calculations_backward(Matrix<float>, float) override;
};