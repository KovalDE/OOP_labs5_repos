#include "Money.h"

using namespace std;

int main()
{
	try
	{
		Object j;
		Money s1, s2(-23, 60);
		cout << endl << "Count = " << Object::Count() << endl;

		cout << "first sum:" << endl;
		cin >> s1;
		cout << s1 << endl << endl;
		Money s3;

		cout << "s2 = " << s2 << endl;
		s3 = ++s2;
		cout << "s3 = ++s2: \n" << "s2 = " << s2 << "s3 = " << s3 << endl;
		s3 = --s2;
		cout << "s3 = --s2: \n" << "s2 = " << s2 << "s3 = " << s3 << endl;
		++s3 = s2++;
		cout << "++s3 = s2++: \n" << "s2 = " << s2 << "s3 = " << s3 << endl;
		--s3 = s2--;
		cout << "--s3 = s2--: \n" << "s2 = " << s2 << "s3 = " << s3 << endl;
		double a = 0;
		Money s;
		cout << endl << "Count = " << Object::Count() << endl;

		cin >> s;
		cout << "Multiplier = "; cin >> a;
		cout << "Mult  = " << s * a;
		cout << endl;
		Money l, r;
		cout << endl << "Count = " << Object::Count() << endl;

		cin >> l; cout << endl;
		cin >> r; cout << endl;
		cout << "Substr = " << l - r;
		if ((l == r) == 1) cout << "summ1 == summ2" << endl;
		if ((l != r) == 1) cout << "summ1 != summ2" << endl;
		if ((l >= r) == 1) cout << "summ1 >= summ2" << endl;
		if ((l <= r) == 1) cout << "summ1 <= summ2" << endl;
		if ((l > r) == 1)  cout << "summ1 >  summ2" << endl;
		if ((l < r) == 1)  cout << "summ1 <  summ2" << endl;
		cout << endl << "Count = " << Object::Count() << endl;
	}
	catch (exception r)
	{
		cerr << "Error number";
	}
	cin.get();
	return 0;
}