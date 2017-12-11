#ifndef __baseobject__h
#define __baseobject__h

#include <string>

class BaseObject
{
	public:
		BaseObject() {}
		virtual ~BaseObject() {}
	public:
		virtual std::string toHtml() = 0;
	private:
		std::string content_;
	public:
		void setContent(const std::string& content)
		{ content_ = content;}
		const std::string& content()const
		{ return content_;}
	protected:
		static std::string brace(const std::string& in);
};
#endif//__baseobject__h
