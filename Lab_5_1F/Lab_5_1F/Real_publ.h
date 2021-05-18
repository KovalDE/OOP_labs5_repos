#pragma once
#include "Number.h"

class Real_publ
	:public Number
{
public:

	Real_publ(const double a = 0);
	Real_publ(const Real_publ& s);

	Real_publ& operator = (const Real_publ& s);

	friend Real_publ operator - (const Real_publ&, const Real_publ&);
	friend Real_publ operator * (const Real_publ&, const Real_publ&);

	/*Real_publ& operator ++ ();
	Real_publ& operator -- ();
	Real_publ operator ++ (int);
	Real_publ operator -- (int);*/

	~Real_publ();

	Real_publ Sqrt(int n);
	static Real_publ PiPower(int n);
};