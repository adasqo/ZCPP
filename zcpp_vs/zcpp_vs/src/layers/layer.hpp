#pragma once
#include "../matrix/matrix.cpp"

class Layer
{
    protected:
        int units;
        int incoming_units;

    public:
        Layer();
        Layer(int);
        Layer(int, int);
        virtual Matrix<float> perform_calculations_forward(Matrix<float>) = 0;
        virtual Matrix<float> perform_calculations_backward(Matrix<float>) = 0;
};
