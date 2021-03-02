#include "data_updater_loader.hpp"
#include <fstream>
#include <sstream>
#include <string>

DataLoader::DataLoader() {};
std::list<Matrix<float>> DataLoader::load_data(std::string file_path)
{
	std::ifstream file(file_path);
    std::string line = "", num;
    std::list<Matrix<float>> output;
    int i = 0, count = 1, j = 0;
    while (getline(file, line))
    {
        std::stringstream rec(line);
        if (i == 0)
        {
            while (getline(rec, num, ','))
                count++;
            i++;
            continue;
        }
        Matrix<float> out = Matrix<float>(count, 1);
        j = 0;
        while (getline(rec, num, ','))
        {
            out(j, 0) = atoi(num.c_str()) - 48;
            j++;
        }
        output.push_back(out);
    }
    return output;
};