#include "Money_publ.h"
#include "Money_priv.h"
using namespace std;

int main()
{
	try {
		Money_publ s1, s2(-23, 60);
		cout << "first sum:" << endl;
		cin >> s1;
		cout << s1 << endl << endl;
		Money_publ s3;
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
		Money_publ s;
		cin >> s;
		cout << "Multiplier = "; cin >> a;
		cout << "Mult  = " << s * a;
		cout << endl;
		Money_publ l, r;
		cin >> l; cout << endl;
		cin >> r; cout << endl;
		cout << "Substr = " << l - r;
		if ((l == r) == 1) cout << "summ1 == summ2" << endl;
		if ((l != r) == 1) cout << "summ1 != summ2" << endl;
		if ((l >= r) == 1) cout << "summ1 >= summ2" << endl;
		if ((l <= r) == 1) cout << "summ1 <= summ2" << endl;
		if ((l > r) == 1)  cout << "summ1 >  summ2" << endl;
		if ((l < r) == 1)  cout << "summ1 <  summ2" << endl;
		cout << "PRIVATE !!!!!!" << endl << endl;
		Money_priv k(9, 50), j;
		cout << k << endl;
		cin >> j;
		cout << "Substr = " << k - j << endl;
		if ((k == j) == 1) cout << "summ1 == summ2" << endl;
		if ((k != j) == 1) cout << "summ1 != summ2" << endl;
		if ((k >= j) == 1) cout << "summ1 >= summ2" << endl;
		if ((k <= j) == 1) cout << "summ1 <= summ2" << endl;
		if ((k > j) == 1)  cout << "summ1 >  summ2" << endl;
		if ((k < j) == 1)  cout << "summ1 <  summ2" << endl;
	}
	catch (exception r)
	{
		cerr << "Error numbers";
	}
	cin.get();
	return 0;
}