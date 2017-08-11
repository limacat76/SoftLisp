#pragma once
#include <vector>
#include "Library.h"

namespace SoftLisp {

	/*
	extern CONSOLEAPPLICATION1_API int nLibrary;
	*/

	SOFTLISP_API int build_test();

	class SOFTLISP_API Parser {
	public:
		Parser();

		std::vector<std::string> parse(std::string input);
	};

}