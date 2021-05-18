#pragma once
#include "Money.h"

class Money_priv
	:private Money
{
public:
	Money_priv();
	Money_priv(long, int);
	Money_priv(const Money_priv&);
	~Money_priv();

	Money_priv& operator = (const Money_priv&);

	friend Money_priv operator - (const Money_priv&, const Money_priv&);
	friend Money_priv operator * (const Money_priv&, double);

	friend ostream& operator << (ostream&, const Money_priv&);
	friend istream& operator >> (istream&, Money_priv&);
	operator string() const;

	friend bool operator == (const Money_priv&, const Money_priv&);
	friend bool operator != (const Money_priv&, const Money_priv&);
	friend bool operator >= (const Money_priv&, const Money_priv&);
	friend bool operator <= (const Money_priv&, const Money_priv&);
	friend bool operator > (const Money_priv&, const Money_priv&);
	friend bool operator < (const Money_priv&, const Money_priv&);

	Money_priv& operator ++();
	Money_priv& operator --();
	Money_priv operator ++(int);
	Money_priv operator --(int);
};