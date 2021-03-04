#include "sequential.hpp"
#include <algorithm>
#include <tuple>

Sequential::Sequential()
{
    layers = std::list<Layer*>();
};
void Sequential::add(Layer& layer)
{
    layers.push_back(&layer);
};
void Sequential::train(int epochs, int batch_size, std::list<Matrix<float>> input, std::list<Matrix<float>> expected)
{
    int batches_count = 0;
    float accuracy;
    std::tuple<std::list<Matrix<float>>, std::list<Matrix<float>>> batch;
    for (int i = 0; i < epochs; ++i)
    {
        std::cout << "Training epoch: " << i + 1 << std::endl;
        
        std::tuple<std::list<Matrix<float>>, std::list<Matrix<float>>> input_shuffled_tuple = shuffle_input(input, expected);

        while(batches_count < input.size())
        {
            batch = create_batch(input_shuffled_tuple, batches_count, batch_size);
            accuracy = perform_batch_calculations(std::get<0>(batch), std::get<1>(batch));
            batches_count += batch_size;
        }
    }
};
std::tuple<std::list<Matrix<float>>, std::list<Matrix<float>>> shuffle_input(std::list<Matrix<float>> input, std::list<Matrix<float>> expected)
{
    return std::make_tuple(input, expected);
}
std::tuple<std::list<Matrix<float>>, std::list<Matrix<float>>> Sequential::create_batch(std::tuple<std::list<Matrix<float>>, std::list<Matrix<float>>> input_shuffled_tuple, int batches_count, int batch_size)
{
    int length = std::get<0>(input_shuffled_tuple).size();
    if (batches_count + batch_size < length)
        batch_size = length - batches_count;

    std::list<Matrix<float>> input;
    std::list<Matrix<float>> expected;
    std::list<Matrix<float>>::iterator it_input = std::get<0>(input_shuffled_tuple).begin();
    std::list<Matrix<float>>::iterator it_expected = std::get<1>(input_shuffled_tuple).begin();
    for (int i = 0; i < batch_size; ++i)
    {
        input.push_back(*it_input);
        expected.push_back(*it_expected);
        it_input++;
        it_expected++;
    }

    return std::make_tuple(input, expected);
}
float Sequential::perform_batch_calculations(std::list<Matrix<float>> input, std::list<Matrix<float>> expected)
{
    std::list<Matrix<float>>::iterator it;
    for (it = input.begin(); it != input.end(); ++it)
    {
        Matrix<float> output = propagate_forward(*it);
    }
}
Matrix<float> Sequential::propagate_forward(Matrix<float> input)
{
    std::list<Layer*>::iterator it;
    for (it = layers.begin(); it != layers.end(); ++it)
    {
        input = (*it)->perform_calculations_forward(input);
        Matrix<float> expected =
            propagate_backward()
    }

    return input;
};
void Sequential::propagate_backward(std::list < Matrix<float> output, Matrix<float> expected)
{
    std::list<Layer*>::iterator it;
    for (it = layers.begin(); it != layers.end(); ++it)
        input = (*it)->perform_calculations_backward(input);
};