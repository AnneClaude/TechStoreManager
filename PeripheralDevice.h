#pragma once
#include "Item.h"
#include "Computer.h"

class Computer;
class PeripheralDevice : virtual public Item
{
protected:
	std::string color;
	bool isWireless;
	Computer* connectedComputer;

public:

	// Constructor:
	PeripheralDevice(int _price = 0, std::string _manu = "~", std::string _color = "~", bool Wireless = false);

	// Destructor:
	virtual ~PeripheralDevice();

	// Getters & Setters:
	Computer* getConnectedComputer() const;
	std::string getColor() const;
	bool getIsWireless() const;

	void setColor(std::string _color);
	void setIsWireless(bool _wireless);
	void setConnectedComputer(Computer* comp);

	//ToString op:
	virtual operator std::string() const;

	//Connect Func:
	virtual void connect(Computer& comp);
	void disconnect();
};
