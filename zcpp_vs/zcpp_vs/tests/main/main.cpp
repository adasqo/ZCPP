#include <iostream>
#include "../../src/layers/dense.hpp"
#include "../../src/models/sequential.hpp"


int main(int argc, char* argv[])
{
    std::cout << "TEST" << std::endl;

    // Matrix<int> m1 = Matrix<int>(2, 2);
    // m1(0, 0) = 1;
    // m1(0, 1) = 1;
    // m1(1, 0) = 1;
    // m1(1, 1) = 1;
    // std::cout << m1 << std::endl;
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
    float input[3] = {0.1, 0.2, 0.3};
    Sequential model = Sequential();
    Dense dense1 = Dense(1);
    model.add(dense1);
    // Dense dense2 = Dense(1);
    // model.add(dense2);
    //model.train();
    // layer.val = 1;
    // std::cout << layer.val << std::endl; 
    
    //system("pause");
    return 0;
}