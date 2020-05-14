#include "ControllerDrug.h"

#include <algorithm>

ControllerDrug::ControllerDrug() {}

ControllerDrug::ControllerDrug(const RepositoryDrug& repo) {
	this->storageDrug = repo;
}

ControllerDrug::~ControllerDrug() {}

void ControllerDrug::add(int ID, std::string name, bool recipe, int stock, std::string producer) {
	std::vector<Drug> drugs = this->storageDrug.getAll();
	bool exists = false;

	for (int i = 0; i < drugs.size(); i++)
		if (ID == drugs[i].getID())
			exists = true;
	if (exists == false) {
		Drug d(ID, name, recipe, stock, producer);
		this->storageDrug.addElement(d);
	}
}

void ControllerDrug::update(int ID, std::string name, bool recipe, int stock, std::string producer) {
	Drug d(ID, name, recipe, stock, producer);
	this->storageDrug.updateElement(d);
}

void ControllerDrug::dell(int ID) {
	std::vector<Drug> drugs = this->storageDrug.getAll();

	for(int i = 0; i < drugs.size(); i++)
		if(ID == drugs[i].getID())
			this->storageDrug.deleteElement(drugs[i]);
}

std::vector<Drug> ControllerDrug::getAll() {
	return this->storageDrug.getAll();
}

int ControllerDrug::getSize() {
	return this->storageDrug.getSize();
}

std::vector<Drug> ControllerDrug::search(std::string drug) {
	std::vector<Drug> storageDrugs = this->storageDrug.getAll();
	std::vector<Drug> result;
	for (int i = 0; i < storageDrugs.size(); i++) {
		std::string name = storageDrugs[i].getName();
		std::transform(name.begin(), name.end(), name.begin(), ::tolower);
		if (name.find(drug) != std::string::npos)
			result.push_back(storageDrugs[i]);
	}
	return result;
}