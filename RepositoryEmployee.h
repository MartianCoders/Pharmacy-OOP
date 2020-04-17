#pragma once

#include "Repository.h"
#include "Objects.h"
#include <string>
#include <fstream>

class RepositoryEmployee : public Repository<Employee> {
public:
	RepositoryEmployee() {};
	RepositoryEmployee(std::string fileName) {
		this->fileName = fileName;
		this->loadFile();
	}
	~RepositoryEmployee() {};

	/* Load file*/
	void loadFile() { // Load data
		if (this->fileName.size() > 0)
		{
			this->clear();
			std::ifstream f(this->fileName);
			int ID;
			std::string name;
			std::string email;
			int grade;
			while (!f.eof())
			{
				f >> ID >> name >> email >> grade;
				if (name.empty() == false)
				{
					this->addElement(Employee(ID, name, email, grade));
				}
			}

			f.close();
		}
	}
};