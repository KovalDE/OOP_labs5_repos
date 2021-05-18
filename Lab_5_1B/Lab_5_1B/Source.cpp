#include "Money.h"
#include "Error.h"
using namespace std;

int main()
{
	try
	{
		Money s1, s2(23, 60);
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
		cin >> s;
		cout << "Multiplier = "; cin >> a;
		cout << "Mult  = " << s * a;
		cout << endl;
		Money res;
		res.SetGR(9);
		res.SetCop(101);
		cout << res;
		/*Money l, r;
		cin >> l; cout << endl;
		cin >> r; cout << endl;
		cout << "Substr = " << l - r;
		if ((l == r) == 1) cout << "summ1 == summ2" << endl;
		if ((l != r) == 1) cout << "summ1 != summ2" << endl;
		if ((l >= r) == 1) cout << "summ1 >= summ2" << endl;
		if ((l <= r) == 1) cout << "summ1 <= summ2" << endl;
		if ((l > r) == 1)  cout << "summ1 >  summ2" << endl;
		if ((l < r) == 1)  cout << "summ1 <  summ2" << endl;*/
	}
	catch (Error r)
	{
		cerr << r.What();
	}
	catch (bad_exception r)
	{
		cerr << r.what();
	}
	catch (exception r)
	{
		cerr << r.what();
	}
	cin.get();
	return 0;
}