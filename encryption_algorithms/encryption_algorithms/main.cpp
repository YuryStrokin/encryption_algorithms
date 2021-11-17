#include "algorithms.h"
#include <fstream>



int main(int argc, char* argv)
{
	string fileNamesInput[]{"data1.txt", "data2.txt", "data3.txt", "data4.txt"};
	string fileNamesOutput[size(fileNamesInput)]{ "result1.txt", "result2.txt", "result3.txt", "result4.txt" };
	for (size_t i = 0; i < size(fileNamesInput); i++)
	{
		ifstream fin(fileNamesInput[i]);
		ofstream fout(fileNamesOutput[i]);
		if (fin.is_open() && fout.is_open())
		{
			cout << fileNamesInput[i] << endl;
			fin.close();
			fout.close();
		}
		else
			cerr << "ERROR!!! The file named " << fileNamesInput[i] << " or " << fileNamesOutput[i] << " did not open." << endl;
	}
	return 0;
};