#pragma once
#include "../matrix/matrix.cpp"
#include <string>

class Layer
{
    protected:
        Matrix<float> result;
        int units;
        int incoming_units;
    public:
        std::string name;
        Layer();
        Layer(int);
        Layer(int, int);
        virtual Matrix<float> perform_calculations_forward(Matrix<float>) = 0;
        virtual Matrix<float> perform_calculations_backward(Matrix<float>, float) = 0;
        virtual std::string return_information();
};
