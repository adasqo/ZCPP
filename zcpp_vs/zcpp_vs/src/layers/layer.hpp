#pragma once
#include "../matrix/matrix.cpp"

class Layer
{
    protected:
        int units;
        int incoming_units;
        Matrix<float> weights;

    public:
        Layer();
        Layer(int);
        Layer(int, int);
        virtual Matrix<float> perform_calculations(Matrix<float>) = 0;
};
