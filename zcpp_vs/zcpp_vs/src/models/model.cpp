#include "model.hpp"
#include <iostream>
#include <math.h>

//Model::Model()
//{
//    layers = std::list<Layer*>();
//};
//void Model::add(Layer& layer)
//{
//    layers.push_back(&layer);
//};
//void Model::train(int epochs, int batches, std::list<Matrix<float>> input, std::list<Matrix<float>> output)
//{
//    int number_batches = input.size() / batches;
//    for (int i = 0; i < epochs; ++i)
//    {
//        std::cout << "Training epoch: " << i + 1 << std::endl;
//        for (int j = 0; j < number_batches; j++)
//        {
//            output = propagate_forward(input);
//        }
//    }
//
//};
//float Model::perform_batch_calculations(std::list<Matrix<float>>, std::list<Matrix<float>>)
//{
//
//}
//Matrix<float> Model::propagate_forward(Matrix<float> input)
//{
//    std::list<Layer*>::iterator it;
//    for (it = layers.begin(); it != layers.end(); ++it)
//    {
//        input = (*it)->perform_calculations_forward(input);
//        Matrix<float> expected = 
//        propagate_backward()
//    }
//
//    return input;
//};
//void Model::propagate_backward(std::list<Matrix<float> output, Matrix<float> expected)
//{
//    std::list<Layer*>::iterator it;
//    for (it = layers.begin(); it != layers.end(); ++it)
//        input = (*it)->perform_calculations_backward(input);
//};