#pragma once
#include <string>
#include "../matrix/matrix.hpp"
#include <list>

class DataLoader
{
	public:
		DataLoader();
		static std::list<Matrix<float>> load_data(std::string);
};