#include "pch.h"
#include "CppUnitTest.h"
#include "../Pr9.2/Pr9.2.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			const int n = 3;
			Student students[n];

			students[0] = { "�����", 1, KN, 80 };
			students[1] = { "���������", 2, IT, 75 };
			students[2] = { "���", 3, ME, 90 };


			int index = BinSearch(students, n, 2, 75, "���������");
			Assert::AreEqual(1, index);


			index = BinSearch(students, n, 4, 80, "Unknown");
			Assert::AreEqual(-1, index);
		}
	};
}