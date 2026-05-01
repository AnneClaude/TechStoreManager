#include "Branch.h"


// Constructor:
Branch::Branch(const std::string _location, const int cap) : capacity(cap)
{
	this->location = _location;
	this->usedcells = 0;
}

// Destructor:
Branch::~Branch() {
	for (int i = 0; i < this->usedcells; i++) {
		delete this->catalog[i];
	}
}

// Copy Constructor:
Branch::Branch(const Branch& other) : capacity(other.getCapacity()) {
	this->location = other.getLocation();
	this->usedcells = 0;
}

// AddItem:
void Branch::addItem(Item* _item) {

	if (this->usedcells == this->capacity) {
		throw FullCatalogError();
	}

	if (std::find(this->catalog.begin(), this->catalog.end(), _item) != this->catalog.end()) {
		throw ExistingItemError();
	}

	this->catalog.push_back(_item);
	this->usedcells++;

}

// removeItem :
Item* Branch::removeItem(const int _id) {
	Item* ret;
	std::vector<Item*>::iterator iter;
	for (iter = catalog.begin(); iter != catalog.end(); ++iter) {
		if ((*iter)->getId() == _id) {
			ret = *iter;
			catalog.erase(iter);  // Erase by iterator
			this->usedcells--;
			return ret;  // Return the removed item
		}
	}
	throw NonExistingItemError();
}


// Getters & Setters:
void Branch::setLocation(const std::string _loc) {
	this->location = _loc;
}

std::string Branch::getLocation() const {
	return this->location;
}

int Branch::getCapacity() const {
	return this->capacity;
}


const std::vector<Item*> Branch::getCatalog() const {
	return this->catalog;
}
