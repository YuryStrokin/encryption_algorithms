#include "BadamshinXOR.h"
#include <sstream>
#include <random>


// Badamshin Marat, XOR
string xorAlgorithms(string& input)
{
	std::string result;
	std::uniform_int_distribution<int> dis(0,256);
	unsigned char key;
	dis(key);
	for (size_t i = 0; i < input.size(); i++)
		result += input[i] ^ key;
	return result;
};