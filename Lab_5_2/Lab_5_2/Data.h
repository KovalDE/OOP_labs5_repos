#pragma once
#include <iostream>
#include<sstream>
#include <string>
#include"Error.h"

using namespace std;
class Data
{
	struct base
	{
		int day;
		int month;
		int year;
	};
	base s;
public:
	void SetDay(int value);
	void SetMonth(int value);
	void SetYear(int value);
	
	int NameOfDay();
	friend ostream& operator << (ostream& out, Data& r);
	friend istream& operator >> (istream& in, Data& r);

	bool check(int, int, int);
};

