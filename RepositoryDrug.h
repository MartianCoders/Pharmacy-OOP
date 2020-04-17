#pragma once
#include "Repository.h"
#include "Objects.h"
#include <string>
#include <fstream>

class RepositoryDrug: public Repository<Drug> {
public:
	RepositoryDrug() {};
	RepositoryDrug(std::string fileName) {
		this->fileName = fileName;
		this->loadFile();
	}
	~RepositoryDrug() {};

	/* Load file*/
	void loadFile() { // Load data
		if (this->fileName.size() > 0)
		{
			this->clear();
			std::ifstream f(this->fileName);
			int ID;
			std::string name;
			std::string producer;
			bool recipe;
			int stock;
			while (!f.eof())
			{
				f >> ID >> name >> recipe >> stock >> producer;
				if (name.empty() == false)
				{
					this->addElement(Drug(ID, name, recipe, stock, producer));
				}
			}

			f.close();
		}
	}
};