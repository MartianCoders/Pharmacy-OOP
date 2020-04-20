#include "UI.h"
#include "ControllerDrug.h"
#include "ControllerEmployee.h"

UI::UI() {}

UI::UI(const ControllerDrug& cd, const ControllerEmployee& ce) {
	this->controllerDrugs = cd;
	this->controllerEmployee = ce;
}

UI::~UI() {}

void UI::showMenu() {
	std::cout << "Type:" << '\n';
	std::cout << "--------------------------" << '\n';
	std::cout << "employee | Employee menu" << '\n';
	std::cout << "drugs    | Drugs menu"<< '\n';
	std::cout << "--------------------------" << '\n';
}

void UI::showEmployeeMenu() {
	std::cout << "(Employee) Type:" << '\n';
	std::cout << "--------------------------" << '\n';
	std::cout << "show    | Show all employee" << '\n';
	std::cout << "add     | Add Employee ({ID} {name} {email} {grade})" << '\n';
	std::cout << "update  | Update Employee ({ID to change} {name} {email} {grade})" << '\n';
	std::cout << "delete  | Delete Employee" << '\n';
	std::cout << "--------------------------" << '\n';
}

void UI::showDrugsMenu() {
	std::cout << "(Drugs) Type:" << '\n';
	std::cout << "--------------------------" << '\n';
	std::cout << "show    | Show all drugs" << '\n';
	std::cout << "add     | Add Employee ({ID} {name} {recipe true/false} {stock} {producer})" << '\n';
	std::cout << "update  | Update Drugs ({ID to change} {name} {recipe true/false} {stock} {producer})" << '\n';
	std::cout << "delete  | Delete Drugs" << '\n';
	std::cout << "--------------------------" << '\n';
}

void UI::showAllE() {
	std::vector<Employee> elements = this->controllerEmployee.getAll();

	for (int i = 0; i < elements.size(); i++)
		std::cout << elements[i] << std::endl;
}

void UI::showAllD() {
	std::vector<Drug> elements = this->controllerDrugs.getAll();

	for (int i = 0; i < elements.size(); i++)
		std::cout << elements[i] << std::endl;
}

void UI::addE(std::string cmd) {
	std::string token;
	std::string sep = " ";
	size_t pos = cmd.find(sep);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int ID = stoi(token);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	std::string name = token;

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	std::string email = token;

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int grade = stoi(token);

	this->controllerEmployee.add(ID, name, email, grade);
}

void UI::addD(std::string cmd) {
	std::string token;
	std::string sep = " ";
	size_t pos = cmd.find(sep);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int ID = stoi(token);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	std::string name = token;

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	bool recipe;
	if (token == "true")
		recipe = true;
	else
		recipe = false;

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int stock = stoi(token);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	std::string producer = token;

	this->controllerDrugs.add(ID, name, recipe, stock, producer);

}

void UI::updateE(std::string cmd) {
	std::string token;
	std::string sep = " ";
	size_t pos = cmd.find(sep);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int ID = stoi(token);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	std::string name = token;

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	std::string email = token;

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int grade = stoi(token);

	this->controllerEmployee.update(ID, name, email, grade);
}

void UI::updateD(std::string cmd) {
	std::string token;
	std::string sep = " ";
	size_t pos = cmd.find(sep);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int ID = stoi(token);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	std::string name = token;

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	bool recipe;
	if (token == "true")
		recipe = true;
	else
		recipe = false;

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int stock = stoi(token);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	std::string producer = token;

	this->controllerDrugs.update(ID, name, recipe, stock, producer);
}

void UI::delE(std::string cmd) {
	std::string token;
	std::string sep = " ";
	size_t pos = cmd.find(sep);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int ID = stoi(token);

	this->controllerEmployee.dell(ID);
}

void UI::delD(std::string cmd) {
	std::string token;
	std::string sep = " ";
	size_t pos = cmd.find(sep);

	cmd.erase(0, pos + sep.length());
	pos = cmd.find(sep);
	token = cmd.substr(0, pos);
	int ID = stoi(token);

	this->controllerDrugs.dell(ID);
}

void UI::employeeMenu() {
	bool exit = false;
	std::string cmd;

	while (exit == false) {
		this->showEmployeeMenu();
		std::getline(std::cin, cmd);
		if (cmd.find("show") != std::string::npos)
			this->showAllE();
		if (cmd.find("add") != std::string::npos)
			this->addE(cmd);
		if (cmd.find("update") != std::string::npos)
			this->updateE(cmd);
		if (cmd.find("delete") != std::string::npos)
			this->delE(cmd);
		if (cmd.find("exit") != std::string::npos) {
			break;
			this->menu();
		}
	}
}

void UI::drugsMenu() {
	bool exit = false;
	std::string cmd;

	while (exit == false) {
		this->showDrugsMenu();
		std::getline(std::cin, cmd);
		if (cmd.find("show") != std::string::npos)
			this->showAllD();
		if (cmd.find("add") != std::string::npos)
			this->addD(cmd);
		if (cmd.find("update") != std::string::npos)
			this->updateD(cmd);
		if (cmd.find("delete") != std::string::npos)
			this->delD(cmd);
		if (cmd.find("exit") != std::string::npos) {
			break;
			this->menu();
		}
	}
}

void UI::menu() {
	bool exit = false;
	std::string cmd;

	while (exit == false) {
		this->showMenu();
		std::getline(std::cin, cmd);
		if (cmd.find("employee") != std::string::npos)
			this->employeeMenu();
		if (cmd.find("drugs") != std::string::npos)
			this->drugsMenu();
		if (cmd.find("exit") != std::string::npos)
			exit = true;
	}
}
