// SoftLisp.cpp : Defines the entry point for the console application.
#include <iostream>
#include <string>
#include <sstream>
#include <conio.h>
#include <boost/program_options.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/functional/factory.hpp>
#include "Catalack.hpp"
#include "Commands/System.h"
#include "Commands/Commands.h"

namespace options = boost::program_options;

int main(int argc, char *argv[]) {
	System *system = &System::get_instance();
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
		std::cout << system->name << "-" << system->version << "\n";
		press_any_key();
		return 1;
	}

	std::map<std::string, Command_Factory> factories;
	factories["quit"] = boost::factory<Quit*>();

	std::cout << "Write 'quit' to exit\n";
	while (!system->quit) {
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