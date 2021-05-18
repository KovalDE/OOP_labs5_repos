#include "Money.h"

#include <sstream>
#include <string>
#include <cmath>

Money::Money()
	:Pair()
{
}

Money::Money(long x, int y)
	: Pair(x, y)
{
}

Money::Money(const Money& x)
	: Pair(x)
{
}

Money::~Money() {}

Money& Money::operator = (const Money& x)
{
	SetGR(x.GetGr());
	SetCop(x.GetCop());
	return *this;
}

Money operator - (const Money& l, const Money& r)
{
	long gr1 = l.GetGr();
	unsigned int cop1 = l.GetCop();
	long gr2 = r.GetGr();
	unsigned int cop2 = r.GetCop();
	if (gr1 > gr2)
	{
		if (cop1 < cop2)
		{
			cop1 += 100;

			gr1 -= 1;
		}
		return Money(gr1 - gr2, cop1 - cop2);
	}
	else
	{
		if (cop2 < cop1)
		{
			cop2 += 100;
			gr2 -= 1;
		}
		return Money(gr2 - gr1, cop2 - cop1);
	}
}

Money operator * (const Money& x, double a)
{
	long double gr1 = x.GetGr();
	unsigned int cop1 = x.GetCop();
	//gr1 = x.gr * a;
	cop1 = x.GetCop() * a + (((x.GetGr() * a) - gr1) * 100);
	while (cop1 >= 100)
	{
		cop1 -= 100;
		gr1 += 1;
	}
	return Money(gr1, cop1);
}

bool operator == (const Money& x, const Money& y)
{
	if (x.GetGr() == y.GetGr() && x.GetCop() == y.GetCop())
		return true;
	else false;
}

bool operator != (const Money& x, const Money& y)
{
	if (x.GetGr() != y.GetGr() && x.GetCop() != y.GetCop())
		return true;
	else false;
}

bool operator >= (const Money& x, const Money& y)
{
	if (x.GetGr() >= y.GetGr() && x.GetCop() >= y.GetCop())
		return true;
	else false;
}

bool operator <= (const Money& x, const Money& y)
{
	if (x.GetGr() <= y.GetGr() && x.GetCop() <= y.GetCop())
		return true;
	else false;
}

bool operator > (const Money& x, const Money& y)
{
	if (x.GetGr() > y.GetGr())
		return true;
	else if (x.GetGr() == y.GetGr() && x.GetCop() > y.GetCop())
		return true;
	else return false;

}

bool operator < (const Money& x, const Money& y)
{
	if (x.GetGr() < y.GetGr() && x.GetCop() < y.GetCop())
		return true;
	else if (x.GetGr() == y.GetGr() && x.GetCop() < y.GetCop())
		return true;
	else return false;
}

Money& Money::operator ++()
{
	SetGR(GetGr() + 1);
	return *this;
}
Money& Money::operator --()
{
	SetGR(GetGr() - 1);
	return *this;
}
Money Money::operator ++(int)
{
	Money t(*this);
	t.SetCop(t.GetCop() + 1);
	if (t.GetCop() == 100)
	{
		t.SetCop(t.GetCop() - 100);
		t.SetGR(t.GetGr() + 1);
	}
	return t;
}
Money Money::operator --(int)
{
	Money t(*this);
	if (t.GetCop() == 100)
	{
		t.SetGR(t.GetGr() - 1);
		t.SetCop(t.GetCop() + 100);
	}
	t.SetCop(t.GetCop() - 1);
	return t;
}
