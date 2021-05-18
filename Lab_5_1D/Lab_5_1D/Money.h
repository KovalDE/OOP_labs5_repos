#pragma once
#include "Pair.h"

class Money
	:public Pair
{
public:
	Money();
	Money(long, int);
	Money(const Money&);
	~Money();

	Money& operator = (const Money& x);

	friend Money operator - (const Money&, const Money&);
	friend Money operator * (const Money&, double);

	friend bool operator == (const Money&, const Money&);
	friend bool operator != (const Money&, const Money&);
	friend bool operator >= (const Money&, const Money&);
	friend bool operator <= (const Money&, const Money&);
	friend bool operator > (const Money&, const Money&);
	friend bool operator < (const Money&, const Money&);

	Money& operator ++();
	Money& operator --();
	Money operator ++(int);
	Money operator --(int);
};

