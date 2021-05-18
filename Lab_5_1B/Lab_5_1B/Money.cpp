#include "Money.h"
#include <sstream>
#include <string>
#include <cmath>
void Money::SetGR(long value)
{
	if (value < 10)
		throw exception("Error my friend! grivna <10");
	else gr = value;
}
void Money::SetCop(unsigned int value) 
{
	if ( value > 100)
		throw exception("Error my friend! copiika >100");
	else cop = value;
}

Money::Money()
{
	gr = 0;
	cop = 0;
}

Money::Money(long x, int y)
{
	if (x < 0 || y < 0)
		throw Error("Error my friend!");
	gr = x;
	cop = y;
}

Money::Money(const Money& x)
{
	gr = x.gr;
	cop = x.cop;
}

Money::~Money() {}

Money& Money::operator = (const Money& x)
{
	gr = x.gr;
	cop = x.cop;

	return *this;
}

ostream& operator << (ostream& out, const Money& x)
{
	out << string(x);
	return out;
}
istream& operator >> (istream& in, Money& x)
{
	long gr1;
	unsigned int cop1;
	cout << "grivnas  = "; in >> gr1;
	cout << "copiikas = "; in >> cop1;
	if (gr1 > 100 || cop1 > 100)
		throw bad_exception();
	else
	{
		x.gr = gr1;
		x.cop = cop1;
	}
	return in;
}

Money::operator string () const
{
	stringstream sout;
	sout << " grivnas = " << gr << '.' << cop << endl;

	return sout.str();
}

Money operator - (const Money& l, const Money& r)
{
	long gr1 = l.gr;
	unsigned int cop1 = l.cop;
	long gr2 = r.gr;
	unsigned int cop2 = r.cop;
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
	long double gr1 = x.gr;
	unsigned int cop1 = x.cop;
	//gr1 = x.gr * a;
	cop1 = x.cop * a + (((x.gr * a) - gr1) * 100);
	while (cop1 >= 100)
	{
		cop1 -= 100;
		gr1 += 1;
	}
	return Money(gr1, cop1);
}

bool operator == (const Money& x, const Money& y)
{
	if (x.gr == y.gr && x.cop == y.cop)
		return true;
	else false;
}

bool operator != (const Money& x, const Money& y)
{
	if (x.gr != y.gr && x.cop != y.cop)
		return true;
	else false;
}

bool operator >= (const Money& x, const Money& y)
{
	if (x.gr >= y.gr && x.cop >= y.cop)
		return true;
	else false;
}

bool operator <= (const Money& x, const Money& y)
{
	if (x.gr <= y.gr && x.cop <= y.cop)
		return true;
	else false;
}

bool operator > (const Money& x, const Money& y)
{
	if (x.gr > y.gr)
		return true;
	else if (x.gr == y.gr && x.cop > y.cop)
		return true;
	else return false;

}

bool operator < (const Money& x, const Money& y)
{
	if (x.gr < y.gr && x.cop < y.cop)
		return true;
	else if (x.gr == y.gr && x.cop < y.cop)
		return true;
	else return false;
}

Money& Money::operator ++()
{
	gr++;
	return *this;
}
Money& Money::operator --()
{
	gr--;
	return *this;
}
Money Money::operator ++(int)
{
	Money t(*this);
	cop++;
	if (cop == 100)
	{
		cop -= 100;
		gr++;
	}
	return t;
}
Money Money::operator --(int)
{
	Money t(*this);
	if (cop == 0)
	{
		gr--;
		cop += 100;
	}
	cop--;
	return t;
}

