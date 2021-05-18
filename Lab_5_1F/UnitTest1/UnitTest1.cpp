#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_5_1F/Real_publ.h"
#include "../Lab_5_1F/Number.h"
#include "../Lab_5_1F/Number.cpp"
#include "../Lab_5_1F/Real_publ.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Real_publ s(9);
			int n = 2;
			Real_publ res = s.Sqrt(n);
			double res1 = res.getDouble();
			Assert::AreEqual(3.0, res1);
		}
	};
}
