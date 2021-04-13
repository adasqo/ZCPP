#include "model.hpp"
#include <iostream>
#include <math.h>
#include "../layers/dense.hpp"
#include "../layers/activation/relu.hpp"
#include "../layers/activation/sigmoid.hpp"
#include "../layers/activation/softmax.hpp"
#include "sequential.hpp"

Model::Model()
{
};
float Model::calculate_error(Matrix<float> output, Matrix<float> expected)
{
    return (output.transpose() * expected)(0, 0);
};

Matrix<float> Model::propagate_forward(Matrix<float>) { return Matrix<float>(); };
void Model::propagate_backward(float, Matrix<float>) {};
float Model::perform_batch_calculations(float, std::list<Matrix<float>>, std::list<Matrix<float>>) { return 0; };
void Model::add(Layer*) {};
std::string Model::train(int, int, float, std::list<Matrix<float>>, std::list<Matrix<float>>) { return ""; };
std::string Model::predict(Matrix<float>) { return ""; };
void Model::save(std::string) {};
Model* Model::load(std::string path)
{
    std::ifstream file(path);
    std::string line, actual_layer;
    int incoming_inputs = 0, units = 0, rows = 0, cols = 0;
    float actv_point = .0, coeff = .0, beta = .0;
    Matrix<float> weigths;
    Layer* layer;
    Model* model = new Model();
    while (std::getline(file, line))
    {
        if (line.find("type") != std::string::npos)
        {
            if (line.find("Sequential") != std::string::npos)
                model = new Sequential();
            continue;
        }
        if (line.find("name") != std::string::npos)
        {
            if (line.find("Dense") != std::string::npos)
                actual_layer = "Dense";
            if (line.find("ReLU") != std::string::npos)
                actual_layer = "ReLU";
            if (line.find("Sigmoid") != std::string::npos)
                actual_layer = "Sigmoid";
            if (line.find("Softmax") != std::string::npos)
                actual_layer = "Softmax";
            continue;
        }
        if (line.find("incoming_inputs") != std::string::npos)
        {
            incoming_inputs = atoi(line.substr(line.find(":") + 2, line.find(",")).c_str());
            continue;
        }
        if (line.find("units") != std::string::npos)
        {
            units = atoi(line.substr(line.find(":") + 2, line.find(",")).c_str());
            continue;
        }
        if (line.find("weights") != std::string::npos)
        {
            int _row = 0, _col = 0;
            while (std::getline(file, line) && line != "}")
            {
                if (line.find("rows") != std::string::npos)
                {
                    rows = atoi(line.substr(line.find(":") + 2, line.find(",")).c_str());
                    continue;
                }
                if (line.find("cols") != std::string::npos)
                {
                    cols = atoi(line.substr(line.find(":") + 2, line.find(",")).c_str());
                    weigths = Matrix<float>(rows, cols);
                    continue;
                }
                if (_col % cols == 0 && _col > 0)
                {
                    _row++;
                    _col = 0;
                }
                if (_row == rows)
                    break;
                weigths(_row, _col) = std::stof(line.substr(0, line.find(",")).c_str());
                _col++;
            }
            Dense* dense = new Dense(incoming_inputs, units);
            dense->set_weights(weigths);
            model->add(dense);
            continue;
        }
        if (line.find("actv_point") != std::string::npos)
        {
            actv_point = std::stof(line.substr(line.find(":") + 2, line.find(",")).c_str());
            continue;
        }
        if (line.find("coeff") != std::string::npos)
        {
            coeff = std::stof(line.substr(line.find(":") + 2, line.find(",")).c_str());
            ReLU* relu = new ReLU(incoming_inputs);
            relu->set_actv_point(actv_point);
            relu->set_coeff(coeff);
            model->add(relu);
            continue;
        }
        if (line.find("beta") != std::string::npos)
        {
            beta = std::stof(line.substr(line.find(":") + 2, line.find(",")).c_str());
            if (actual_layer == "Sigmoid")
            {
                Sigmoid* sigmoid = new Sigmoid(incoming_inputs);
                sigmoid->set_beta(beta);
                model->add(sigmoid);
                continue;
            }
            if (actual_layer == "Softmax")
            {
                Softmax* softmax = new Softmax(incoming_inputs);
                softmax->set_beta(beta);
                model->add(softmax);
                continue;
            }
        }
    }
    return model;
}