#include "Money_publ.h"


Money_publ::Money_publ()
	:Money()
{
}

Money_publ::Money_publ(long x, int y)
	: Money(x, y)
{
}

Money_publ::Money_publ(const Money_publ& x)
	: Money(x)
{
}

Money_publ::~Money_publ() {}

Money_publ& Money_publ::operator = (const Money_publ& x)
{
	SetGR(x.GetGr());
	SetCop(x.GetCop());

	return *this;
}

Money_publ operator - (const Money_publ& l, const Money_publ& r)
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
		return Money_publ(gr1 - gr2, cop1 - cop2);
	}
	else
	{
		if (cop2 < cop1)
		{
			cop2 += 100;
			gr2 -= 1;
		}
		return Money_publ(gr2 - gr1, cop2 - cop1);
	}
}

Money_publ operator * (const Money_publ& x, double a)
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
	return Money_publ(gr1, cop1);
}

bool operator == (const Money_publ& x, const Money_publ& y)
{
	if (x.GetGr() == y.GetGr() && x.GetCop() == y.GetCop())
		return true;
	else false;
}

bool operator != (const Money_publ& x, const Money_publ& y)
{
	if (x.GetGr() != y.GetGr() && x.GetCop() != y.GetCop())
		return true;
	else false;
}

bool operator >= (const Money_publ& x, const Money_publ& y)
{
	if (x.GetGr() >= y.GetGr() && x.GetCop() >= y.GetCop())
		return true;
	else false;
}

bool operator <= (const Money_publ& x, const Money_publ& y)
{
	if (x.GetGr() <= y.GetGr() && x.GetCop() <= y.GetCop())
		return true;
	else false;
}

bool operator > (const Money_publ& x, const Money_publ& y)
{
	if (x.GetGr() > y.GetGr())
		return true;
	else if (x.GetGr() == y.GetGr() && x.GetCop() > y.GetCop())
		return true;
	else return false;

}

bool operator < (const Money_publ& x, const Money_publ& y)
{
	if (x.GetGr() < y.GetGr() && x.GetCop() < y.GetCop())
		return true;
	else if (x.GetGr() == y.GetGr() && x.GetCop() < y.GetCop())
		return true;
	else return false;
}

Money_publ& Money_publ::operator ++()
{
	SetGR(GetGr() + 1);
	return *this;
}
Money_publ& Money_publ::operator --()
{
	SetGR(GetGr() - 1);
	return *this;
}
Money_publ Money_publ::operator ++(int)
{
	Money_publ t(*this);
	t.SetCop(t.GetCop() + 1);
	if (t.GetCop() == 100)
	{
		t.SetCop(t.GetCop() - 100);
		t.SetGR(t.GetGr() + 1);
	}
	return t;
}
Money_publ Money_publ::operator --(int)
{
	Money_publ t(*this);
	if (t.GetCop() == 100)
	{
		t.SetGR(t.GetGr() - 1);
		t.SetCop(t.GetCop() + 100);
	}
	t.SetCop(t.GetCop() - 1);
	return t;
}

