#ifndef __TRANSLATOR__H
#define __TRANSLATOR__H

#include <string>

class Translator
{
	public:
		Translator();
		~Translator();
	public:
		std::string translate(const std::string& markdown);
};
#endif//__TRANSLATOR__H
