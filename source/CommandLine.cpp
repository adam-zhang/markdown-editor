#include "CommandLine.h"
#include "Error.h"
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;


int analyzeCommandLine(const vector<string>& vec)
{
	int error = 0;
	auto ret = for_each(vec.begin(), vec.end(), [&error](const string& fileName)
			{
				fstream file(fileName, ios_base::in);
				if (!file)
					error = ERROR_FILE_DOES_NOT_EXIST;
				return 0;
			});

	return error;
}


int CommandLine::analyze(int argc, char** argv)
{
	if (argc < 2)
		return ERROR_PARAMETERS_NUMBER;
	vector<string> vec;
	for(int i = 0; i < argc; ++i)
		vec.push_back(argv[i]);
	return analyzeCommandLine(vec);
}


