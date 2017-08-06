// SoftLisp.cpp : Defines the entry point for the console application.
#include <iostream>
#include <string>
#include <sstream>
#include <conio.h>
#include <boost/program_options.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/functional/factory.hpp>
#include "Catalack.hpp"

namespace options = boost::program_options;

const std::string name = "SoftLisp";

const std::string version = "0.0.0.1";

class Command {
public:
	virtual void execute() = 0;
};

bool system_quit = false;

class Quit : public Command {
public:
	void execute() {
		system_quit = true;
	}
};

typedef boost::function<Command*() > Command_Factory;

int main(int argc, char *argv[]) {
	options::options_description desc("Allowed options");
	desc.add_options()
		("help", "produce an help message")
		("version", "show version")
		;

	options::variables_map vm;
	options::store(options::parse_command_line(argc, argv, desc), vm);
	options::notify(vm);

	if (vm.count("help")) {
		std::cout << desc << "\n";
		press_any_key();
		return 1;
	}

	if (vm.count("version")) {
		std::cout << name << "-" << version << "\n";
		press_any_key();
		return 1;
	}

	std::map<std::string, Command_Factory> factories;
	factories["quit"] = boost::factory<Quit*>();

	std::cout << "Write 'quit' to exit\n";
	while (!system_quit) {
		std::cout << "> ";

		std::string input;
		std::cin >> input;

		auto search = factories.find(input);
		if (search != factories.end()) {
			std::cout << "Found " << search->first << " " << search->second << '\n';
			Command_Factory value = search->second;
			Command* x = value();
			x->execute();
		} else {
			std::cout << "#ECHO# " << input << "\n";
		}
	}

    return 0;
}

