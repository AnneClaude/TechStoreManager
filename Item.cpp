#include "Item.h"
#include <iostream>
#include <string>


int Item::lastId = 0;


// Constructor:
Item::Item(int pr, const std::string& manu) : id(++lastId), price(pr), manufacturer(manu) { }

// Destructor:
Item::~Item() {
	std::cout << "Throwing away an item" << std::endl;
}


//To String Func (Operator Overload):
Item::operator std::string() const {
	return ("id " + std::to_string(this->id) + ": " + this->manufacturer + ", " + std::to_string(this->price) + "$,");
}


//Getters & Setters:
std::string Item::getManufacturer() const {
	return this->manufacturer;
}

int Item::getId() const {
	return this->id;
}

int Item::getPrice() const {
	return this->price;
}

// ------------------------------------

void Item::setId(const int _id) {
	this->id = _id;
}

void Item::setPrice(const int _price) {
	this->price = _price;
}

void Item::setManufacturer(const std::string manu) {
	this->manufacturer = manu;
}

// Comprator:
bool Item::itemPtrCompare(const Item* a, const Item* b) {
	return (a->getId() < b->getId());
}
