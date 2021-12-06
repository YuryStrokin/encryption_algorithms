#include "BadamshinXOR.h"
#include "cRC4.h"
#include <fstream>
#include <vector>



int main(int argc, char* argv)
{
	vector<string>fileNamesInput {"data1.txt", "data2.txt", "data3.txt", "data4.txt"};
	vector<string>fileNamesOutput { "result1.txt", "result2.txt", "result3.txt", "result4.txt" };
	ifstream fin;
	ofstream fout;
	string data;
	string resultStr;
	for (size_t i = 0; i < fileNamesInput.size(); i++)
	{
		fin.open(fileNamesInput[i]);
		fout.open(fileNamesOutput[i]);
		if (fin.is_open() && fout.is_open())
		{
			while (!fin.eof())
			{
				getline(fin, data);

			}
		}
		else
			cerr << "ERROR!!! The file named " << fileNamesInput[i] << " or " << fileNamesOutput[i] << " did not open." << endl;
		fin.close();
		fout.close();
	}
	return 0;
};