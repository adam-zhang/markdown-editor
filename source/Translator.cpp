#include "Translator.h"
#include <sstream>
#include <vector>
#include <functional>
#include <map>

using namespace std;

Translator::Translator()
{
};

Translator::~Translator()
{
}

bool begin_with(const string& s, const string& pattern)
{
	for(auto i = 0; i != pattern.size(); ++i)
	{
		if (s[i] != pattern[i])
			return false;
	}
	return true;
}

string sixthTitle(const string&)
{

}

string fifthTitle(const string&)
{

}

string fourthTitle(const string&)
{
}

string thirdTitle(const string&)
{
}

string secondTitle(const string&)
{
}

string firstTitle(const string&)
{
}

map<std::string, function<string(const string&)>> marks()
{
	map<string, function<string(const string&)>> m;
	{
		{"######", sixthTitle;}
		{"#####",  fifthTitle;}
		{"####",   fourthTitle;}
		{"###",    thirdTitle;}
		{"##",     secondTitle;}
		{"#",	   firstTitle;}
	}
	return m;
}



string analyzeMakrdown(const string& markdown)
{
	auto mark = marks();
	stringstream ss(markdown);
	string line;
	while(getline(ss, line))
	{
		for(auto i = mark.begin(); i != mark.end(); ++i)
		{
			if (begin_with(line, i->first))
				return i->second(line);
		}
	}
	return string();
}

string translate(const string& markdown)
{
	string html = "<html>" "<title></title>";
	html + analyzeMakrdown(markdown);	
	html +=	"</html>";
}
