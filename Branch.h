#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "Item.h"
#include "HWExceptions.h"

class Branch
{
private:
	int usedcells;

	std::vector<Item*> catalog;

	std::string location;

	const int capacity;

public:

	// Constructor:
	Branch(const std::string _location = "~", const int cap = 0);

	// Destructor:
	~Branch();

	// Copy Constructor:
	Branch(const Branch& other);

	// AddItem :
	void addItem(Item* _item);

	// removeItem :
	Item* removeItem(const int _id);

	// Give me your finest :
	template <class T>
	inline T* giveMeFinest(T* subClass) const {

		int maxPrice = 0;
		T* ptrMaxItem = nullptr;
		std::vector<Item*>::const_iterator iter = this->catalog.begin();

		for (; iter != catalog.end(); ++iter) {
			T* current;
			if (current = dynamic_cast<T*>(*iter)) {
				if ((typeid(*current) == typeid(*subClass)) && (current->getPrice() > maxPrice)) {
					ptrMaxItem = current;
					maxPrice = current->getPrice();
				}
			}
		}

		// in case there is no item with the same type:
		if (ptrMaxItem == nullptr) throw NoneExistingItemTypeError();

		return ptrMaxItem;
	}

	//Getters & Setters:
	std::string getLocation() const;
	const std::vector<Item*> getCatalog() const;
	int getCapacity() const;

	void setLocation(const std::string _loc);
};


