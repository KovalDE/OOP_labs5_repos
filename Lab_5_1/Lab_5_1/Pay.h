#pragma once
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Pay
{
	double first;
	int second;
public:
	Pay();
	Pay(double, int);
	Pay(const Pay&);
	~Pay();
	double GetFirst() const;
	int GetSecond() const;
	void SetFirst(double value);
	void SetSecond(int value);
	Pay& operator = (const Pay&);
	operator string() const;
	friend Pay operator + (const Pay& , const Pay& );
	friend Pay operator - (const Pay& , const Pay& );
	friend Pay operator * (const Pay& , const Pay& );
	friend Pay operator / (const Pay&, const Pay& );
	friend Pay operator ^ (const Pay& , const Pay& );
	friend ostream& operator << (ostream& , const Pay& );
	friend istream&  operator >> (istream& , Pay& );
	Pay&  operator ++();
	Pay&  operator --();

	Pay operator ++(int);
	Pay operator --(int);
	double summa(int k);

};