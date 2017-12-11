#ifndef __orderedlist__h
#define __orderedlist__h

#include "BaseObject.h"

class OrderedList : public BaseObject
{
	public:
	       	OrderedList();
		~OrderedList();
	public:
		std::string toHtml();
};
#endif//__orderedlist__h
