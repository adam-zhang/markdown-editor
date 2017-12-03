#include <iostream>
#include "CommandLine.h"

int main(int argc, char** argv)
{
	int ret = CommandLine::analyze(argc, argv);
	if (ret)
	{
		std::cout << ret << std::endl;
		return ret;
	}
	return 0;

}
