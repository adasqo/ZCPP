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
        void update_weights(std::tuple<Matrix<float>, Matrix<float>> derivative, float alpha);
    public:
        Dense();
        Dense(int);
        Dense(int, int);

        Matrix<float> perform_calculations_forward(Matrix<float>) override;
        std::tuple<Matrix<float>, Matrix<float>> perform_calculations_backward(std::tuple<Matrix<float>, Matrix<float>>, float) override;
};