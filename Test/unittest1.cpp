#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Library/System.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Assert::AreEqual(42, fnLibrary(), L"message", LINE_INFO());
		}

	};
}