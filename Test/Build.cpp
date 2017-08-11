#include <vector>
#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Library/System.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test {		

	TEST_CLASS(Build) {
	public:		
		TEST_METHOD(Non_Regression) {
			Assert::AreEqual(42, SoftLisp::build_test(), L"problem with building", LINE_INFO());
		}
	};

}