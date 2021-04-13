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

    DataLoader loader = DataLoader();
    std::cout << "Loading data..." << std::endl;
    std::tuple<std::list<Matrix<float>>, std::list<Matrix<float>>> data;
    data = loader.load_data("../../data/train.csv", 10);
    std::cout << "Data loaded" << std::endl;

    Model* model = new Sequential();
    Dense dense1 = Dense(784, 256);
    model->add(&dense1);
    ReLU relu1 = ReLU(256);
    model->add(&relu1);
    Dense dense2 = Dense(256, 128);
    model->add(&dense2);
    Sigmoid sigmoid1 = Sigmoid(128);
    model->add(&sigmoid1);
    Dense dense3 = Dense(128, 10);
    model->add(&dense3);
    Softmax soft1 = Softmax(10);
    model->add(&soft1);
    model->train(1, 10, 0.001, std::get<0>(data), std::get<1>(data));
    model->save("./model_test.txt");
    Model* model2 = model->load("./model_test.txt");
    model2->predict(*(std::get<0>(data).begin()));
    return 0;
}