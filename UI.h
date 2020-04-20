#pragma once
#include "ControllerDrug.h"
#include "ControllerEmployee.h"

class UI {
private:
	ControllerDrug controllerDrugs;
	ControllerEmployee controllerEmployee;
public:
	UI();
	UI(const ControllerDrug&, const ControllerEmployee&);
	~UI();

	/* Menu's*/
	void menu();
	void showMenu();
	void showEmployeeMenu();
	void showDrugsMenu();
	void employeeMenu();
	void drugsMenu();

	/* Commands | Employee */
	void showAllE();
	void addE(std::string);
	void updateE(std::string);
	void delE(std::string);

	/* Commands | Drugs */
	void showAllD();
	void addD(std::string);
	void updateD(std::string);
	void delD(std::string);
};