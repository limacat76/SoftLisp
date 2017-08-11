#include "stdafx.h"
#include "System.h"

namespace SoftLisp {

	SOFTLISP_API int build_test() {
		return 42;
	}

	Parser::Parser() {
		;
	}

	std::vector<std::string> Parser::parse(std::string input) {
		std::vector<std::string> result;
		bool in_string = false;
		std::string token = "";

		for (int i = 0; i < input.size(); i++) {
			token += input[i];
		}

		result.push_back(token);
		return result;
	}
	
}