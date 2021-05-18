#pragma once
#include "Number.h"

class Real
	:public Number
{
public:

	Real(const double a = 0);
	Real(const Real& s);

	Real& operator = (const Real& s);

	friend Real operator - (const Real&, const Real&);
	friend Real operator * (const Real&, const Real&);

	/*Real& operator ++ ();
	Real& operator -- ();
	Real operator ++ (int);
	Real operator -- (int);*/

	~Real();

	Real Sqrt(int n);
	static Real PiPower(int n);
};