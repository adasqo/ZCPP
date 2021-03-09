#pragma once

#include "../../matrix/matrix.cpp"
#include "../layer.hpp"

class ActivationLayer: public Layer
{
    private:
        virtual float calculate_result(float) = 0;
        virtual float calculate_derivative(float) = 0;
    protected:
        Matrix<float> result;
        virtual Matrix<float> transfer_result(Matrix<float>);
        virtual std::tuple<Matrix<float>, Matrix<float>> transfer_derivative(Matrix<float>);
    public:
        ActivationLayer();
        ActivationLayer(int);
        Matrix<float> perform_calculations_forward(Matrix<float>) override;
        std::tuple<Matrix<float>, Matrix<float>> perform_calculations_backward(std::tuple<Matrix<float>, Matrix<float>>, float) override;
};
