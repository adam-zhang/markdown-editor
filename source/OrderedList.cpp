#include "OrderedList.h"
#include <sstream>

using namespace std;

OrderedList::OrderedList()
{}

OrderedList::~OrderedList()
{
}

string OrderedList::toHtml()
{
	stringstream ss(content());
	string line;
	while(getline(ss, line))
	{
		
	}
}
