#pragma once
#include "Money.h"

class Money_publ
	:public Money
{
public:
	Money_publ();
	Money_publ(long, int);
	Money_publ(const Money_publ&);
	~Money_publ();

	Money_publ& operator = (const Money_publ&);

	friend Money_publ operator - (const Money_publ&, const Money_publ&);
	friend Money_publ operator * (const Money_publ&, double);

	friend bool operator == (const Money_publ&, const Money_publ&);
	friend bool operator != (const Money_publ&, const Money_publ&);
	friend bool operator >= (const Money_publ&, const Money_publ&);
	friend bool operator <= (const Money_publ&, const Money_publ&);
	friend bool operator > (const Money_publ&, const Money_publ&);
	friend bool operator < (const Money_publ&, const Money_publ&);

	Money_publ& operator ++();
	Money_publ& operator --();
	Money_publ operator ++(int);
	Money_publ operator --(int);
};

