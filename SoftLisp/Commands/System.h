#pragma once
#include <string>


// for now System is a singleton, it needs to change
class System {
private:
	System();
	~System();
public:
	bool quit = false;

	const std::string name = "SoftLisp";

	const std::string version = "0.0.0.2";

	static System& get_instance();
};