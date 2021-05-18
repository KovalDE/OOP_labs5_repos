#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_5_1/Pay.h"
#include "../Lab_5_1/Pay.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Pay k(2.0, 2);
			int r = 1;
			double s = 0;
			s = k.summa(r);
			Assert::AreEqual(s, 4.0);
		}
	};
}
