#include "Objects.h"

Drug::Drug() {
	this->ID = 0;
	this->recipe = false;
	this->stock = 0;
}

Drug::Drug(int ID, std::string name, bool recipe, int stock, std::string producer) {
	this->ID = ID;
	this->name = name;
	this->recipe = recipe;
	this->stock = stock;
	this->producer = producer;
}

Drug::Drug(const Drug& d) {
	this->ID = d.ID;
	this->name = d.name;
	this->recipe = d.recipe;
	this->stock = d.stock;
	this->producer = d.producer;
}

Drug::~Drug() {}

int Drug::getID() {
	return this->ID;
}

std::string Drug::getName() {
	return this->name;
}

bool Drug::getRecipe() {
	return this->recipe;
}

int Drug::getStock() {
	return this->stock;
}

std::string Drug::getProducer() {
	return this->producer;
}

void Drug::setID(int ID) {
	this->ID = ID;
}

void Drug::setName(std::string name) {
	this->name = name;
}

void Drug::setRecipe(bool recipe) {
	this->recipe = recipe;
}

void Drug::setStock(int stock) {
	this->stock = stock;
}

void Drug::setProducer(std::string prod) {
	this->producer = prod;
}

Drug& Drug::operator=(const Drug& d) {
	this->setID(d.ID);
	this->setName(d.name);
	this->setRecipe(d.recipe);
	this->setStock(d.stock);
	this->setProducer(d.producer);
	return *this;
}

bool Drug::operator==(const Drug& d) const {
	if (this->ID == d.ID && this->name == d.name && this->recipe == d.recipe && this->stock == d.stock && this->producer == d.producer)
		return true;
	return false;
}

bool Drug::operator!=(const Drug& d) const {
	if (this->ID == d.ID && this->name == d.name && this->recipe == d.recipe && this->stock == d.stock && this->producer == d.producer)
		return false;
	return true;
}

std::ostream& operator<<(std::ostream& os, const Drug& d) {
	os << d.ID << ": " << d.name << ", recipe: " << std::boolalpha << d.recipe << ", " << d.stock << ", " << d.producer << '\n';
	return os;
}
