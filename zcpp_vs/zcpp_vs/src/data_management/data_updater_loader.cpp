#include "data_updater_loader.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <tuple>

DataLoader::DataLoader() {};
std::tuple<std::list<Matrix<float>>, std::list<Matrix<float>>> DataLoader::load_data(std::string file_path, int number_samples)
{
	std::ifstream file(file_path);
    std::string line = "", num;
    std::list<Matrix<float>> output;
    std::list<Matrix<float>> expected;
    int i = 0, count = 0, j = 0;
    while (getline(file, line) && i <= number_samples)
    {
        std::stringstream rec(line);
        if (i == 0)
        {
            while (getline(rec, num, ','))
                count++;
            i++;
            continue;
        }
        Matrix<float> exp = Matrix<float>(10, 1);
        Matrix<float> out = Matrix<float>(count - 1, 1);
        j = 0;
        while (getline(rec, num, ','))
        {
            if (j == 0)
            {
                exp(atoi(num.c_str()), 0) = 1;
                j++;
                continue;
            }
            out(j - 1, 0) = float((float)atoi(num.c_str()) / (float)255);
            j++;
        }
        output.push_back(out);
        expected.push_back(exp);
        i++;
    }
    return std::make_tuple(output, expected);
};