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
#include "UI.h"

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
	assert(string.str() == "2 Andrei andrei@gmail.com 2");
}

void test_Drug() {
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
	assert(string.str() == "2 Ospen true 25 Bayer");
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
	
	std::string drug = "nuro";
	std::vector<Drug> result = controllerDrug.search(drug);
	for (int i = 0; i < result.size(); i++)
		assert(result[i].getName() == "Nurofen");
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
	assert(controllerEmployee.changeGrade(1, 2, 6) == true);
	assert(controllerEmployee.changeGrade(1, 6, 1) == false);
	controllerEmployee.dell(1);
	assert(controllerEmployee.getSize() == 0);
}

void test_login() {
	RepositoryEmployee testStorageEmpl("tests.txt");
	RepositoryDrug testStorageDrug("tests.txt");
	ControllerDrug contrDrug(testStorageDrug);
	ControllerEmployee contrEmp(testStorageEmpl);
	UI ui(contrDrug, contrEmp);
	Employee e1(1, "Teodor", "info.teodor@gmail.com", 10);
	Employee e2(0, "", "", 0);
	contrEmp.add(1, "Teodor", "info.teodor@gmail.com", 10);
	assert(contrEmp.checkDataLogin("info.teodor@gmail.com", "info.teodor") == e1);
	assert(contrEmp.checkDataLogin("info.teodor@gmail.com", "da") == e2);
	contrEmp.dell(1);
}

void test_lab() {
	RepositoryDrug repoDrug;
	ControllerDrug service(repoDrug);
	Drug m1(100, "parasinus", false, 10, "p1");
	Drug m2(200, "ketonal", false, 90, "p2");
	Drug m3(300, "antibiotic", true, 70, "p3");

	//service.add(m1);
	//service.add(m2);
	assert(service.getAll().size() == 2);
	assert(service.getAll()[0] == m1);
	assert(service.getAll()[1] == m2);
	//service.add(m3);
	assert(service.getAll()[2] == m3);

	assert(service.search("ic").size() == 1);
	assert(service.search("a").size() == 3);

	Drug m1_new(100, "altceva", false, 50, "p1");
	//service.update(m1, m1_new);
	assert(service.search("al").size() == 2);
	assert(service.search("al")[0] == m1_new);
	assert(service.search("al")[1] == m2);
	service.dell(200);
	assert(service.search("al").size() == 1);
	assert(service.search("al")[0] == m1_new);
}

void test_all() {
	test_employee();
	test_Drug();
	test_repoDrug();
	test_repoEmployee();
	test_contDrug();
	test_contEmployee();
	test_login();
	//test_lab();
}