#pragma once
#include "../matrix/matrix.hpp"

class Layer
{
    protected:
        int units;
        int incoming_units;
        Matrix<float> m;

    public:
        Layer()
        {
            m = Matrix<float>();
        };
        Layer(int units): units(units)
        {
            m = Matrix<float>();
        };
        Layer(int units, int incoming_units): units(units), incoming_units(incoming_units) 
        {
             m = Matrix<float>(incoming_units + 1, units);
        };
        virtual Matrix<float> perform_calculations(Matrix<float>)
        {
            return Matrix<float>();
        };
};
