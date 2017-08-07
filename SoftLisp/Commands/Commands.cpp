#include "Commands.h"

void Quit::execute() {
	System *system = &System::get_instance();
	system->quit = true;
}
