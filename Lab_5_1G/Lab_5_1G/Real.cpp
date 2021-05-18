#include "Real.h"
#include <iostream>

using namespace std;

Real Real::Sqrt(int n)
{
	Real t(pow(getDouble(), 1. / n));
	return t;
}

Real Real::PiPower(int n)
{
	double pi = atan(1) * 4;
	Real t(pow(pi, n));
	return t;
}

Real::Real(const double a)
	: Number(a)
{}
Real::Real(const Real& s)
	: Number(s)
{
}
Real& Real::operator =(const Real& s)
{
	Number::operator =(s);
	return *this;
}

/*Real& Real::operator ++ () {
	setDouble(getDouble()+1);
	return	*this;
}
Real& Real::operator -- () {
	setDouble(getDouble() - 1);
	return *this;
}
Real Real::operator ++(int)
{
	Real s(*this);
	number++;
	return s;
}
Real Real::operator --(int)
{
	Real s(*this);
	number--;
	return s;
}*/
Real::~Real(void)
{}

Real operator - (const Real& l, const Real& r)
{
	double a1 = l.getDouble();
	double a2 = r.getDouble();
	Real t(a1 - a2);
	return t;
}

Real operator * (const Real& l, const Real& r)
{
	double a1 = l.getDouble();
	double a2 = r.getDouble();
	Real t(a1 * a2);
	return t;
}