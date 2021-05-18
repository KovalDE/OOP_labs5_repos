#include "Real_publ.h"
#include <iostream>

using namespace std;

Real_publ Real_publ::Sqrt(int n)
{
	Real_publ t(pow(getDouble(), 1. / n));
	return t;
}

Real_publ Real_publ::PiPower(int n)
{
	double pi = atan(1) * 4;
	Real_publ t(pow(pi, n));
	return t;
}

Real_publ::Real_publ(const double a)
	: Number(a)
{}
Real_publ::Real_publ(const Real_publ& s)
	: Number(s)
{
}
Real_publ& Real_publ::operator =(const Real_publ& s)
{
	Number::operator =(s);
	return *this;
}

/*Real_publ& Real_publ::operator ++ () {
	setDouble(getDouble()+1);
	return	*this;
}
Real_publ& Real_publ::operator -- () {
	setDouble(getDouble() - 1);
	return *this;
}
Real_publ Real_publ::operator ++(int)
{
	Real_publ s(*this);
	number++;
	return s;
}
Real_publ Real_publ::operator --(int)
{
	Real_publ s(*this);
	number--;
	return s;
}*/
Real_publ::~Real_publ(void)
{}

Real_publ operator - (const Real_publ& l, const Real_publ& r)
{
	double a1 = l.getDouble();
	double a2 = r.getDouble();
	Real_publ t(a1 - a2);
	return t;
}

Real_publ operator * (const Real_publ& l, const Real_publ& r)
{
	double a1 = l.getDouble();
	double a2 = r.getDouble();
	Real_publ t(a1 * a2);
	return t;
}