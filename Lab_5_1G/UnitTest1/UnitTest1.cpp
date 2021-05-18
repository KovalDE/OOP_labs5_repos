#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_5_1G/Real.h"
#include "../Lab_5_1G/Real.cpp"
#include "../Lab_5_1G/Object.h"
#include "../Lab_5_1G/Object.cpp"
#include "../Lab_5_1G/Number.h"
#include "../Lab_5_1G/Number.cpp"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Real s(9);
			int n = 2;
			Real res = s.Sqrt(n);;
			double res1 = res.getDouble();
			Assert::AreEqual(3.0, res1);
		}
	};
}
