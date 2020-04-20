#include <iostream>
#include <crtdbg.h>

#include "tests.h"
#include "UI.h"
#include "ControllerDrug.h"
#include "RepositoryDrug.h"
#include "RepositoryEmployee.h"
#include "ControllerEmployee.h"

int main() {
	test_all();
	RepositoryDrug storageDrugs("drugs.txt");
	RepositoryEmployee storageEmployee("employee.txt");
	ControllerDrug controllerDrug(storageDrugs);
	ControllerEmployee controllerEmployee(storageEmployee);
	UI ui(controllerDrug, controllerEmployee);
	ui.menu();
	_CrtDumpMemoryLeaks();
}