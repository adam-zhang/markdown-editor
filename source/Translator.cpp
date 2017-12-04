#include "Translator.h"
#include <algorithm>
#include <cassert>
#include <fstream>
#include <iostream>
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

string markup(const string& mark,const string& s)
{
	stringstream ss;
	ss << "<" << mark << ">" << s << "</" << mark << ">";
	return ss.str();
}

string sixthTitle(const string& s)
{
	return markup("h6", s.substr(7));
}

string fifthTitle(const string& s)
{
	return markup("h5", s.substr(6));
}

string fourthTitle(const string& s)
{
	return markup("h4", s.substr(5));
}

string thirdTitle(const string& s)
{
	return markup("h3", s.substr(4));
}

string secondTitle(const string& s)
{
	return markup("h2", s.substr(3));
}

string firstTitle(const string& s)
{
	return markup("h1", s.substr(2));
}

map<std::string, function<string(const string&)>> marks()
{
	map<string, function<string(const string&)>> m =
	{
		{"###### ", sixthTitle},
		{"##### ",  fifthTitle},
		{"#### ",   fourthTitle},
		{"### ",    thirdTitle} ,
		{"## ",     secondTitle},
		{"# ",	   firstTitle}
	};
	return m;
}

string analyzeLine(const string& line)
{
	auto m = marks();
	string s;
	for_each(m.begin(), m.end(), [&s, &line](auto p)
			{
				if (begin_with(line, p.first))
				{
					s = p.second(line);
					return;
				}
			});
	return s;
}


string analyzeMakrdown(const string& markdown)
{
	stringstream ss(markdown);
	string line;
	string result;
	while(getline(ss, line))
	{
		result += analyzeLine(line);
	}
	return result;
}

string readFile(const string& fileName)
{
	ifstream file;
	file.open(fileName, ios_base::in);
	file.seekg(0, ios::end);
	size_t size = file.tellg();
	assert(size > 0);
	file.seekg(0, ios::beg);
	vector<char> buffer(size);
	file.read(&buffer[0], size);
	return &buffer[0];
}

string Translator::translate(const string& fileName)
{
	string content = readFile(fileName);
	string html = "<html>" "<title></title><body>";
	html += analyzeMakrdown(content);	
	html +=	"</body></html>";
	return html;
}
