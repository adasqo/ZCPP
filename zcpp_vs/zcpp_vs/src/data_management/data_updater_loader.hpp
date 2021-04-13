#pragma once
#include <string>
#include "../matrix/matrix.hpp"
#include <list>

class DataLoader
{
	public:
		DataLoader();
		std::tuple<std::list<Matrix<float>>, std::list<Matrix<float>>> load_data(std::string, int);
};