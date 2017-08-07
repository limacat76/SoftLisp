#pragma once
#include <boost/functional/factory.hpp>
#include <boost/algorithm/string.hpp>
#include "System.h"

class Command {
public:
	virtual void execute() = 0;
};

class Quit : public Command {
public:
	void execute();
};

typedef boost::function<Command*()> Command_Factory;
