#include "Pay.h"
#include <sstream>
#include <string>
double Pay::GetFirst() const
{
	return first;
}
int Pay::GetSecond() const
{
	return second;
}
void Pay::SetFirst(double value)
{
	if (value> 0)
		first = value;
	else
		throw bad_exception();

}
void Pay::SetSecond(int value)
{
	if (value > 0)
		second = value;
	else
		throw bad_exception();

}
Pay::Pay()
{
	first = 0;
	second = 0;
}
Pay::Pay(double x, int y)
{
	if (x < 0 || y < 0) throw bad_exception();
	first = x;
	second = y;
}
Pay::Pay(const Pay&   x)
{
	first = x.first;
	second = x.second;
}
Pay::~Pay() {}
Pay&   Pay::operator = (const Pay& x)
{
	first = x.first;
	second = x.second;

	return *this;
}
Pay::operator string () const
{
	stringstream sout;
	sout<< " first = " << first<< endl;
	sout<< " second = " << second<< endl;
	return sout.str();
}
Pay operator + (const Pay&   x, const Pay&   y)
{
	return Pay(x.first + y.first, x.second + y.second);
}
Pay operator - (const Pay&   x, const Pay&   y)
{
	return Pay(x.first - y.first, x.second - y.second);
}
Pay operator * (const Pay&   x, const Pay&   y)
{
	return Pay(x.first * y.first, x.second * y.second);
}
Pay operator / (const Pay&   x, const Pay&   y)
{
	return Pay((x.first) / (y.first), (x.second) / (y.second));
}
Pay operator ^ (const Pay& x, const unsigned n)
{
	Pay y(1, 0);
	for (unsigned i = 1; i <=n; i++)
		y = y * x;
	return y;
}
ostream&   operator << (ostream&   out, const Pay&   x)
{
	out<< string(x);
	return out;
}
istream&   operator >> (istream&   in, Pay&   x)
{
	double first1;
	int second1;
	cout<< "First = "; in>> first1;
	cout<< "Second = "; in>> second1;
	x.SetFirst(first1);
	x.SetSecond(second1);
	return in;
}
Pay&   Pay::operator ++()
{
	first++;
	return *this;
}
Pay&   Pay::operator --()
{
	first--;
	return *this;
}
Pay Pay::operator ++(int)
{
	Pay t(*this);
	second++;
	return t;
}
Pay Pay::operator --(int)
{
	Pay t(*this);
	second--;
	return t;
}

double Pay::summa(int k)
{
	return first / k * second;
}