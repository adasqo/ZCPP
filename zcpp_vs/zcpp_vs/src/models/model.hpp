#pragma once
#include "../layers/dense.hpp"
#include <list>
#include <string>
#include <QTextEdit>

class Model
{
    private:
        virtual Matrix<float> propagate_forward(Matrix<float>);
        virtual void propagate_backward(float, Matrix<float>);
        virtual float perform_batch_calculations(float, std::list<Matrix<float>>, std::list<Matrix<float>>);
    protected:
        QTextEdit* console;
        std::list<Layer*> layers;
        float calculate_error(Matrix<float> output, Matrix<float> expected);
    public:
        Model(QTextEdit* console = nullptr);
        virtual void add(Layer*);
        virtual void train(int, int, float, std::list<Matrix<float>>, std::list<Matrix<float>>);
        virtual void predict(Matrix<float>);
};
