#ifndef __title__h
#define __title__h

#include "BaseObject.h"

class Title //: public BaseObject
{
	public:
		Title();
		virtual ~Title();
	public:
		virtual std::string toHtml();
};
#endif//__title__h
