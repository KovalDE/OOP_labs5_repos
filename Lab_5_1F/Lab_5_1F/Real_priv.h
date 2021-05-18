#pragma once
#include "Number.h"

class Real_priv
	:private Number
{
public:

	Real_priv(const double a = 0);
	Real_priv(const Real_priv& s);

	Real_priv& operator = (const Real_priv& s);
	operator string () const;

	friend ostream& operator << (ostream& out, const Real_priv& a);
	friend istream& operator >> (istream& in, Real_priv& a);

	friend Real_priv operator - (const Real_priv&, const Real_priv&);
	friend Real_priv operator * (const Real_priv&, const Real_priv&);

	/*Real_priv& operator ++ ();
	Real_priv& operator -- ();
	Real_priv operator ++ (int);
	Real_priv operator -- (int);
	*/
	~Real_priv();

	Real_priv Sqrt(int n);
	static Real_priv PiPower(int n);
};