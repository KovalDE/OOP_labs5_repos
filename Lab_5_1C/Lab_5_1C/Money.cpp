#include "Money.h"
#include <sstream>
#include <string>
#include <cmath>

long Money::excGR(long gr1)
{
	if (gr1 < 0) throw exception();
	if (gr1 == 0) throw Error("Number 0 is bad");
	return gr1;
}

int Money::excCOP(int cop1)
{
	if (cop1 < 0) throw bad_exception();
	if (cop1 == 0) throw Error("Number 0 is bad");
	else return cop1;
}

Money::Money()
{
	gr = 0;
	cop = 0;
}

Money::Money(long x, int y)
try : gr(excGR(x)),cop(excCOP(y))
	{

	}
catch (bad_exception r)
{
	cerr << r.what();
}
catch(exception)
{
	cerr << "Invalid number";
}
catch (Error r)
{
	cerr << r.What();
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
	cout << "grivnas  = "; in >> x.gr;
	cout << "copiikas = "; in >> x.cop;
	return in;
}

Money::operator string () const
{
	stringstream sout;
	sout << " grivnas = " << gr << '.' << cop << endl;

	return sout.str();
}



