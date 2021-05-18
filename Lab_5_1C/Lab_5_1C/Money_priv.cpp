#include "Money_priv.h"


Money_priv::Money_priv()
	:Money()
{
}

Money_priv::Money_priv(long x, int y)
	: Money(x, y)
{
}

Money_priv::Money_priv(const Money_priv& x)
	: Money(x)
{
}

Money_priv::~Money_priv() {}

Money_priv& Money_priv::operator = (const Money_priv& x)
{
	SetGR(x.GetGr());
	SetCop(x.GetCop());

	return *this;
}

ostream& operator << (ostream& out, const Money_priv& x)
{
	out << string(x);
	return out;
}
istream& operator >> (istream& in, Money_priv& x)
{
	long gr1;
	unsigned int cop1;

	cout << "grivnas  = "; in >> gr1;
	x.SetGR(gr1);
	cout << "copiikas = "; in >> cop1;
	x.SetCop(cop1);
	return in;
}

Money_priv::operator string () const
{
	stringstream sout;
	sout << " grivnas = " << GetGr() << '.' << GetCop() << endl;

	return sout.str();
}

Money_priv operator - (const Money_priv& l, const Money_priv& r)
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
		return Money_priv(gr1 - gr2, cop1 - cop2);
	}
	else
	{
		if (cop2 < cop1)
		{
			cop2 += 100;
			gr2 -= 1;
		}
		return Money_priv(gr2 - gr1, cop2 - cop1);
	}
}

Money_priv operator * (const Money_priv& x, double a)
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
	return Money_priv(gr1, cop1);
}

bool operator == (const Money_priv& x, const Money_priv& y)
{
	if (x.GetGr() == y.GetGr() && x.GetCop() == y.GetCop())
		return true;
	else false;
}

bool operator != (const Money_priv& x, const Money_priv& y)
{
	if (x.GetGr() != y.GetGr() && x.GetCop() != y.GetCop())
		return true;
	else false;
}

bool operator >= (const Money_priv& x, const Money_priv& y)
{
	if (x.GetGr() >= y.GetGr() && x.GetCop() >= y.GetCop())
		return true;
	else false;
}

bool operator <= (const Money_priv& x, const Money_priv& y)
{
	if (x.GetGr() <= y.GetGr() && x.GetCop() <= y.GetCop())
		return true;
	else false;
}

bool operator > (const Money_priv& x, const Money_priv& y)
{
	if (x.GetGr() > y.GetGr())
		return true;
	else if (x.GetGr() == y.GetGr() && x.GetCop() > y.GetCop())
		return true;
	else return false;

}

bool operator < (const Money_priv& x, const Money_priv& y)
{
	if (x.GetGr() < y.GetGr() && x.GetCop() < y.GetCop())
		return true;
	else if (x.GetGr() == y.GetGr() && x.GetCop() < y.GetCop())
		return true;
	else return false;
}

Money_priv& Money_priv::operator ++()
{
	SetGR(GetGr() + 1);
	return *this;
}
Money_priv& Money_priv::operator --()
{
	SetGR(GetGr() - 1);
	return *this;
}
Money_priv Money_priv::operator ++(int)
{
	Money_priv t(*this);
	t.SetCop(t.GetCop() + 1);
	if (t.GetCop() == 100)
	{
		t.SetCop(t.GetCop() - 100);
		t.SetGR(t.GetGr() + 1);
	}
	return t;
}
Money_priv Money_priv::operator --(int)
{
	Money_priv t(*this);
	if (t.GetCop() == 100)
	{
		t.SetGR(t.GetGr() - 1);
		t.SetCop(t.GetCop() + 100);
	}
	t.SetCop(t.GetCop() - 1);
	return t;
}





