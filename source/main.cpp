#include <iostream>
#include "CommandLine.h"
//#include "Translator.h"

int main(int argc, char** argv)
{
	int ret = CommandLine::analyze(argc, argv);
	if (ret)
	{
		std::cout << ret << std::endl;
		return ret;
	}
	//Translator translator;
	//std::cout << translator.translate(argv[1]) << std::endl;
	return 0;

}
