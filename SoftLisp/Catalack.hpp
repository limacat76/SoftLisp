#include <iostream>
#include <boost/program_options.hpp>

// version 1.0.0.1
#ifndef CATALACK_COMMON
#define CATALACK_COMMON

#if defined(_MSC_VER)
# pragma once
#endif

namespace options = boost::program_options;

template <typename T> inline T getParameter(options::variables_map value_map, std::string parameter_key) {
	T result = value_map[parameter_key].as<T>();
#ifdef _DEBUG
	std::cout << parameter_key << ":=" << result << "\n";
#endif
	return result;
}

inline void press_any_key() {
	std::cin.clear();
#pragma warning( push ) 
#pragma warning( disable : 6031) 
	std::cout << "Press any key to exit \n";
	_getch();
#pragma warning( pop ) 
}

#endif