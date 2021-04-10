#include <iostream>
#include "../../src/layers/dense.hpp"
#include "../../src/models/sequential.hpp"
#include "../../src/layers/activation/relu.hpp"
#include "../../src/layers/activation/sigmoid.hpp"
#include "../../src/layers/activation/softmax.hpp"
#include "../../src/data_management/data_updater_loader.hpp"
#include <tuple>

int main(int argc, char* argv[])
{
    std::cout << "TEST" << std::endl;

   /*  Matrix<int> m1 = Matrix<int>(2, 2);
     m1(0, 0) = 1;
     m1(0, 1) = 1;
     m1(1, 0) = 1;
     m1(1, 1) = 1;
     std::cout << m1 << std::endl;*/
    // Matrix<int> m2 = Matrix<int>(2, 2);
    // m2(0, 0) = 1;
    // m2(0, 1) = 2;
    // m2(1, 0) = 3;
    // m2(1, 1) = 4;
    // std::cout << m2 << std::endl;
    // Matrix<int> m3 = m1 + m2;
    // std::cout << m3 << std::endl;
    // Matrix<int> m4 = m1 * m2;
    // std::cout << m4 << std::endl;
    // Matrix<int> m5 = m1 * 5;
    // std::cout << m5 << std::endl;
    // Matrix<int> m6 = m2.transpose();
    // std::cout << m6 << std::endl;

    DataLoader loader = DataLoader();
    std::cout << "Loading data..." << std::endl;
    std::tuple<std::list<Matrix<float>>, std::list<Matrix<float>>> data;
    data = loader.load_data("../../data/train.csv", 10);
    std::cout << "Data loaded" << std::endl;
    
    /*Matrix<float> input1 = Matrix<float>(2, 1);
    input1(0, 0) = 0.1;
    input1(1, 0) = -0.1;
    Matrix<float> input2 = Matrix<float>(2, 1);
    input2(0, 0) = -0.1;
    input2(1, 0) = 0.1;
    Matrix<float> output1 = Matrix<float>(2, 1);
    output1(0, 0) = 0;
    output1(1, 0) = 1;
    Matrix<float> output2 = Matrix<float>(2, 1);
    output2(0, 0) = 1;
    output2(1, 0) = 0;
    std::list<Matrix<float>> input;
    input.push_back(input1);
    input.push_back(input2);
    std::list<Matrix<float>> expected;
    expected.push_back(output1);
    expected.push_back(output2);*/

    Model* model = new Sequential();
    Dense dense1 = Dense(784, 10);
    model->add(dense1);
    /*ReLU relu1 = ReLU(128);
    model.add(relu1);*/
    Sigmoid sigmoid1 = Sigmoid(10);
    /*model->add(sigmoid1);
    Dense dense2 = Dense(128, 10);
    model->add(dense2);*/
    Softmax soft1 = Softmax(10);
    model->add(soft1);
    model->train(100, 10, 0.001, std::get<0>(data), std::get<1>(data));

    // layer.val = 1;
    // std::cout << layer.val << std::endl; 
    
    //system("pause");
    return 0;
}