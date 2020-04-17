#include <assert.h>
#include <sstream>
#include <iostream>

#include "tests.h"
#include "Objects.h"
#include "Repository.h"
#include "RepositoryDrug.h"
#include "RepositoryEmployee.h"
#include "ControllerDrug.h"
#include "ControllerEmployee.h"

void test_employee() {
	Employee e;
	Employee ee(e);
	Employee e1(1, "Teodor", "info.teodor@gmail.com", 5);
	assert(e1.getID() == 1);
	assert(e1.getName() == "Teodor");
	assert(e1.getEmail() == "info.teodor@gmail.com");
	assert(e1.getGrade() == 5);
	Employee e2(2, "Andrei", "andrei@gmail.com", 2);
	assert(e1 == e2 == false);
	assert(e1 != e2 == true);
	e1 = e2;
	assert(e1 == e2 == true);
	assert(e1 != e2 == false);
	std::stringstream string;
	string << e1;
	assert(string.str() == "2: Andrei, andrei@gmail.com, 2\n");
}

void test_drug() {
	Drug d;
	Drug dd(d);
	Drug d1(1, "Paracetamol", false, 50, "RoFarm");
	assert(d1.getID() == 1);
	assert(d1.getName() == "Paracetamol");
	assert(d1.getRecipe() == false);
	assert(d1.getStock() == 50);
	assert(d1.getProducer() == "RoFarm");
	Drug d2(2, "Ospen", true, 25, "Bayer");
	assert(d1 == d2 == false);
	assert(d1 != d2 == true);
	d1 = d2;
	assert(d1 == d2 == true);
	assert(d1 != d2 == false);
	std::stringstream string;
	string << d1;
	assert(string.str() == "2: Ospen, recipe: true, 25, Bayer\n");
}

void test_repoDrug() {
	RepositoryDrug storageDrugs("tests.txt");
	Drug d1(1, "Paracetamol", false, 50, "RoFarm");
	storageDrugs.addElement(d1);
	assert(storageDrugs.getSize() == 1);
	assert(storageDrugs.getAll()[0] == d1);
	storageDrugs.deleteElement(d1);
	assert(storageDrugs.getSize() == 0);
}

void test_repoEmployee() {
	RepositoryEmployee storageEmployee("tests.txt");
	Employee e1(1, "Teodor", "info.teodor@gmail.com", 5);
	storageEmployee.addElement(e1);
	assert(storageEmployee.getSize() == 1);
	assert(storageEmployee.getAll()[0] == e1);
	storageEmployee.deleteElement(e1);
	assert(storageEmployee.getSize() == 0);
}

void test_contDrug() {
	ControllerDrug controllerDrugTest;
	RepositoryDrug storageDrugs("tests.txt");
	ControllerDrug controllerDrug(storageDrugs);
	Drug d1(1, "Paracetamol", false, 50, "RoFarm");
	Drug d2(1, "Nurofen", true, 25, "Ro");
	controllerDrug.add(1, "Paracetamol", false, 50, "RoFarm");
	controllerDrug.add(1, "Nurofen", true, 25, "Ro");
	assert(controllerDrug.getSize() == 1);
	assert(controllerDrug.getAll()[0] == d1);
	controllerDrug.update(1, "Nurofen", true, 25, "Ro");
	assert(controllerDrug.getAll()[0] == d2);
	controllerDrug.dell(1);
	assert(controllerDrug.getSize() == 0);
}

void test_contEmployee() {
	ControllerEmployee controllerEmployeeTest;
	RepositoryEmployee storageEmployee("tests.txt");
	ControllerEmployee controllerEmployee(storageEmployee);
	Employee e1(1, "Teodor", "info.teodor@gmail.com", 5);
	Employee e2(1, "Andrei", "andrei@gmail.com", 3);
	controllerEmployee.add(1, "Teodor", "info.teodor@gmail.com", 5);
	controllerEmployee.add(1, "Andrei", "andrei@gmail.com", 3);
	assert(controllerEmployee.getSize() == 1);
	assert(controllerEmployee.getAll()[0] == e1);
	controllerEmployee.update(1, "Andrei", "andrei@gmail.com", 3);
	assert(controllerEmployee.getAll()[0] == e2);
	controllerEmployee.dell(1);
	assert(controllerEmployee.getSize() == 0);
}

void test_all() {
	test_employee();
	test_drug();
	test_repoDrug();
	test_repoEmployee();
	test_contDrug();
	test_contEmployee();
}