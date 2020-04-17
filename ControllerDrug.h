#pragma once
#include "RepositoryDrug.h"

class ControllerDrug {
private:
	RepositoryDrug storageDrug;
public:
	/* Constructor & Destructor */
	ControllerDrug(); // Default
	ControllerDrug(const RepositoryDrug&); // Given Repository
	~ControllerDrug(); // Destructor

	/* CRUD's */
	void add(int, std::string, bool, int, std::string); // Add element (In: ID, name, recipe, stock, producer)
	void update(int, std::string, bool, int, std::string); // Update element by ID (In: ID, name, recipe, stock, producer)
	void dell(int); // Delete element by ID (In: ID)

	/* Get's */
	std::vector<Drug> getAll();
	int getSize();
};