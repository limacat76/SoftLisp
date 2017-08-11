#include <vector>
#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Library/System.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test {

	TEST_CLASS(Parser) {
private:
	void test_vectors(std::vector<std::string> expected, std::vector<std::string> result) {
		Assert::AreEqual(expected.size(), result.size(), L"Sizes not equal between vectors", LINE_INFO());
		for (int i = 0; i < expected.size(); i++) {
			Assert::AreEqual(expected[i], result[i], L"Content not equal between vectors", LINE_INFO());
		}
	}

public:
	TEST_METHOD(wikipedia_test) {
		SoftLisp::Parser parser;

		std::string test_expression = "(+ 5 (+ 3 5))";
		std::vector<std::string> expected = { "(", "+", "5", "(", "+", "3", "5", ")", ")" };

		test_vectors(expected, parser.parse(test_expression));
	}

	TEST_METHOD(atom_token_1) {
		SoftLisp::Parser parser;

		std::string test_expression = "94";
		std::vector<std::string> expected = { "94" };

		test_vectors(expected, parser.parse(test_expression));
	}


	};

}