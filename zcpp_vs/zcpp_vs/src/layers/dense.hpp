#pragma once
#include "layer.hpp"
#include "../matrix/matrix.hpp"

class Dense: public Layer
{
    private:
        void initiatie_weights();
    public:
        Dense();
        Dense(int);
        Dense(int, int);

        Matrix<float> perform_calculations(Matrix<float>) override;
};