#ifndef __stringassistant__h
#define __stringassistant__h

template<typename T>
bool begin_with(const std::basic_string<T>& origin, const std::basic_string<T>& pattern)
{
	for(size_t i = 0; i < pattern.size(); ++i)
	{
		if (pattern[i] != origin[i])
			return false;
	}
	return true;
}
#endif//__stringassistant__h
