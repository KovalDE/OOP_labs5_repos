#pragma once
#include "Error.h"
class Object
{
	static unsigned int count;
public:
	static unsigned int Count()
	{
		return count;
	}
	Object()
	{
		count++;
	}
	~Object()
	{
		count--;
	}
};