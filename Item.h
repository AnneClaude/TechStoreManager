#pragma once

#include <iostream>
#include <string>

class Item
{
private:

	static int lastId;

	int price;

	std::string manufacturer;

	int id;

public:

	// Constructor:
	Item(int pr = 0, const std::string& manu = "~");

	// Destructor:
	virtual ~Item();

	//To String Func (Operator Overload):
	virtual operator std::string() const;

	//Getters & Setters:
	std::string getManufacturer() const;
	int getId() const;
	int getPrice() const;

	void setId(const int _id);
	void setPrice(const int _price);
	void setManufacturer(const std::string manu);

	//Comprator:
	static bool itemPtrCompare(const Item* a, const Item* b);
};


