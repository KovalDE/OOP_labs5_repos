#include <iostream>
#include <string>
#include "Real_priv.h"
#include "Real_publ.h"

using namespace std;

int main()
{
	try {
		Real_publ s(-9);
		int n;
		cout << "N: "; cin >> n;
		cout << "SQRT : ";
		cout << s.Sqrt(n);
		cout << endl;
		cout << "Pi in power of number : ";
		cout << s.PiPower(n);
		cout << endl;
		cout << endl;
		Real_publ l, r;
		cin >> l;
		cin >> r;
		cout << endl;
		Real_publ res;
		res = l * r;
		cout << "Result of multiplier   = " << res.getDouble() << endl;
		res = l - r;
		cout << "Result of substraction = " << res.getDouble() << endl;
		cout << endl << "PRIVATE!!!!!" << endl;
		Real_priv k(2);
		cout << "K = " << k;
		cout << "N: "; cin >> n;
		cout << "SQRT : ";
		cout << k.Sqrt(n);
	}
	catch (exception r)
	{
		cerr << "Error number";
	}
	return 0;
}