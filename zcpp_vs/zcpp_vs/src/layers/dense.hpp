#pragma once
#include "layer.hpp"
#include "../matrix/matrix.hpp"

class Dense: public Layer
{
    private:
        Matrix<float> weights;
        void initiatie_weights();
    public:
        Dense();
        Dense(int);
        Dense(int, int);

        Matrix<float> perform_calculations_forward(Matrix<float>) override;
};