#pragma once
#include "../layers/dense.hpp"
#include <list>
#include <string>
#include <fstream>

class Model
{
    private:
        virtual Matrix<float> propagate_forward(Matrix<float>);
        virtual void propagate_backward(float, Matrix<float>);
        virtual float perform_batch_calculations(float, std::list<Matrix<float>>, std::list<Matrix<float>>);
    protected:
        std::list<Layer*> layers;
        float calculate_error(Matrix<float> output, Matrix<float> expected);
    public:
        Model();
        virtual void add(Layer*);
        virtual std::string train(int, int, float, std::list<Matrix<float>>, std::list<Matrix<float>>);
        virtual std::string predict(Matrix<float>);
        virtual void save(std::string);
        virtual Model* load(std::string);
};
