#include "sequential.hpp"
#include <algorithm>
#include <tuple>
#include <vector>

Sequential::Sequential()
{
    layers = std::list<Layer*>();
};
void Sequential::add(Layer& layer)
{
    layers.push_back(&layer);
};
void Sequential::train(int epochs, int batch_size, float alpha, std::list<Matrix<float>> input, std::list<Matrix<float>> expected)
{
    int batches_count;
    float error, err = 0;
    std::tuple<std::list<Matrix<float>>, std::list<Matrix<float>>> batch;
    for (int i = 0; i < epochs; ++i)
    {
        std::cout << "Training epoch: " << i + 1 << std::endl;
        
        batches_count = 0;
        std::tuple<std::list<Matrix<float>>, std::list<Matrix<float>>> input_shuffled_tuple = shuffle_input(input, expected);
        error = 0;
        while(batches_count < input.size())
        {
            std::cout << "Batch #: " << batches_count << std::endl;
            batch = create_batch(input_shuffled_tuple, batches_count, batch_size);
            err = perform_batch_calculations(alpha, std::get<0>(batch), std::get<1>(batch));
            std::cout << "Error: " << err << std::endl;
            error += err;
            batches_count += batch_size;
        }
        std::cout << std::endl << "Error: " << error << std::endl;
    }
};
std::tuple<std::list<Matrix<float>>, std::list<Matrix<float>>> Sequential::shuffle_input(std::list<Matrix<float>> input, std::list<Matrix<float>> expected)
{
    std::list<Matrix<float>>::iterator input_it = input.begin();
    std::list<Matrix<float>>::iterator expected_it = expected.begin();
    std::vector<std::tuple<Matrix<float>, Matrix<float>>> vec;
    for (input_it; input_it != input.end(); ++input_it)
    {
        vec.push_back(std::make_tuple(*input_it, *expected_it));
        expected_it++;
    }
    std::random_shuffle(vec.begin(), vec.end());
    std::list<Matrix<float>> input_out;
    std::list<Matrix<float>> expected_out;
    for (std::vector<std::tuple<Matrix<float>, Matrix<float>>>::iterator vec_it = vec.begin(); vec_it != vec.end(); ++vec_it)
    {
        input_out.push_back(std::get<0>(*vec_it));
        expected_out.push_back(std::get<1>(*vec_it));
    }
    return std::make_tuple(input_out, expected_out);
}
std::tuple<std::list<Matrix<float>>, std::list<Matrix<float>>> Sequential::create_batch(std::tuple<std::list<Matrix<float>>, std::list<Matrix<float>>> input_shuffled_tuple, int batches_count, int batch_size)
{
    int length = std::get<0>(input_shuffled_tuple).size();
    if (batches_count + batch_size >= length)
        batch_size = length - batches_count;

    std::list<Matrix<float>> input;
    std::list<Matrix<float>> expected;
    std::list<Matrix<float>>::iterator it_input = std::get<0>(input_shuffled_tuple).begin();
    std::list<Matrix<float>>::iterator it_expected = std::get<1>(input_shuffled_tuple).begin();
    std::advance(it_input, batches_count);
    std::advance(it_expected, batches_count);
    for (int i = 0; i < batch_size; ++i)
    {
        input.push_back(*it_input);
        expected.push_back(*it_expected);
        it_input++;
        it_expected++;
    }

    return std::make_tuple(input, expected);
}
float Sequential::perform_batch_calculations(float alpha, std::list<Matrix<float>> input, std::list<Matrix<float>> expected)
{
    std::list<Matrix<float>>::iterator it;
    std::list<Matrix<float>>::iterator exp = expected.begin();
    float err = 0;;
    for (it = input.begin(); it != input.end(); ++it)
    {
        Matrix<float> output = propagate_forward(*it);
        std::cout << "Expected: " << argmax(*exp) << " calculated: " << argmax(output) << std::endl;
        Matrix<float> error = Matrix<float>(output.get_rows(), 1);
        for (int i = 0; i < error.get_rows(); i++)
        {
            error(i, 0) = (*exp)(i, 0) - output(i, 0);
            //error(i, 0) = log(output(i, 0)) * ((*exp)(i, 0)) + log(1 - output(i, 0)) * (1 - (*exp)(i, 0));
            err += abs(error(i, 0));
        }
        //std::cout << "out: " << output << std::endl;
        exp++;
        propagate_backward(alpha, error);
    }
    return err / input.size();
}
Matrix<float> Sequential::propagate_forward(Matrix<float> input)
{
    std::list<Layer*>::iterator it;
    for (it = layers.begin(); it != layers.end(); ++it)
        input = (*it)->perform_calculations_forward(input);

    return input;
};
void Sequential::propagate_backward(float alpha, Matrix<float> output)
{
    std::list<Layer*>::reverse_iterator it;
    std::tuple<Matrix<float>, Matrix<float>> out = std::make_tuple(output, Matrix<float>());

    for (it = layers.rbegin(); it != layers.rend(); it++)
        out = (*it)->perform_calculations_backward(out, alpha);
};
int Sequential::argmax(Matrix<float> m)
{
    int index = 0;
    for (int i = 1; i < m.get_rows(); i++)
        if (m(i, 0) > m(index, 0))
            index = i;
    return index;
}