#include "Pair.h"

#include <sstream>
#include <string>
#include <cmath>

long Pair::excGR(long gr1)
{
	if (gr1 < 0) throw exception();
	if (gr1 == 0) throw Error("Number 0 is bad");
	return gr1;
}

int Pair::excCOP(int cop1)
{
	if (cop1 < 0) throw bad_exception();
	if (cop1 == 0) throw Error("Number 0 is bad");
	else return cop1;
}

Pair::Pair()
{
	gr = 0;
	cop = 0;
}

Pair::Pair(long x, int y)
try : gr(excGR(x)), cop(excCOP(y))
{

}
catch (bad_exception r)
{
	cerr << r.what();
}
catch (exception)
{
	cerr << "Invalid number";
}
catch (Error r)
{
	cerr << r.What();
}

Pair::Pair(const Pair& x)
{
	gr = x.gr;
	cop = x.cop;
}

Pair::~Pair() {}

Pair& Pair::operator = (const Pair& x)
{
	gr = x.gr;
	cop = x.cop;

	return *this;
}

ostream& operator << (ostream& out, const Pair& x)
{
	out << string(x);
	return out;
}
istream& operator >> (istream& in, Pair& x)
{
	cout << "grivnas  = "; in >> x.gr;
	cout << "copiikas = "; in >> x.cop;
	return in;
}

Pair::operator string () const
{
	stringstream sout;
	sout << " grivnas = " << gr << '.' << cop << endl;

	return sout.str();
}


bool operator ==(const Pair& t1, const Pair& t2)
{
	return t1.GetGr() == t2.GetGr() && t1.GetCop() == t2.GetCop();
}
bool operator >(const Pair& t1, const Pair& t2)
{
	return t1.GetGr() > t2.GetGr() && t1.GetGr() == t2.GetGr() && t1.GetCop() > t2.GetCop();
}
bool operator <(const Pair& t1, const Pair& t2)
{
	return t1.GetGr() < t2.GetGr() && t1.GetGr() == t2.GetGr() && t1.GetCop() < t2.GetCop();
}

bool operator >=(const Pair& t1, const Pair& t2)
{
	return !(t1 < t2);
}
bool operator <=(const Pair& t1, const Pair& t2)
{
	return !(t1 > t2);
}
bool operator !=(const Pair& t1, const Pair& t2)
{
	return !(t1 == t2);
}



