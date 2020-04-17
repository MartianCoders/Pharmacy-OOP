#include <iostream>
#include <crtdbg.h>

#include "tests.h"

int main() {
	test_all();
	_CrtDumpMemoryLeaks();
}