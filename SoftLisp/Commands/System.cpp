#include "System.h"
// for now System is a singleton, it needs to change

System::System() {
	;
}

System::~System() {
	;
}

System& System::get_instance() {
	static System S;
	return S;
}