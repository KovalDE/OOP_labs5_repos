#include "Real_priv.h"
#include <iostream>

using namespace std;

Real_priv Real_priv::Sqrt(int n)
{
	Real_priv t(pow(getDouble(), 1. / n));
	return t;
}

Real_priv Real_priv::PiPower(int n)
{
	double pi = atan(1) * 4;
	Real_priv t(pow(pi, n));
	return t;
}

Real_priv::Real_priv(const double a)
	: Number(a)
{}
Real_priv::Real_priv(const Real_priv& s)
	: Number(s)
{
}
Real_priv& Real_priv::operator =(const Real_priv& s)
{
	setDouble(s.getDouble());
	return *this;
}

/*Real_priv& Real_priv::operator ++ () {
	setDouble(getDouble()+1);
	return	*this;
}
Real_priv& Real_priv::operator -- () {
	setDouble(getDouble() - 1);
	return *this;
}
Real_priv Real_priv::operator ++(int)
{
	Real_priv s(*this);
	number++;
	return s;
}
Real_priv Real_priv::operator --(int)
{
	Real_priv s(*this);
	number--;
	return s;
}*/
Real_priv::~Real_priv(void)
{}

ostream& operator << (ostream& out, const Real_priv& a)
{
	out << string(a);
	return out;
}

istream& operator >> (istream& in, Real_priv& a)
{
	double a1;
	cout << "summa = ? "; in >> a1;
	a.setDouble(a1);
	cout << endl;
	return in;
};


Real_priv::operator string () const
{
	stringstream ss;
	ss << endl;
	ss << "summa = " << getDouble() << endl;
	return ss.str();
}


Real_priv operator - (const Real_priv& l, const Real_priv& r)
{
	double a1 = l.getDouble();
	double a2 = r.getDouble();
	Real_priv t(a1 - a2);
	return t;
}

Real_priv operator * (const Real_priv& l, const Real_priv& r)
{
	double a1 = l.getDouble();
	double a2 = r.getDouble();
	Real_priv t(a1 * a2);
	return t;
}