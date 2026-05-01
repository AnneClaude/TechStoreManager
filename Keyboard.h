#pragma once
#include "PeripheralDevice.h"

class Keyboard : public PeripheralDevice
{
private:
	int numberOfKeys;

public:

	// Constructor:
	Keyboard(int _price = 0, std::string _manu = "~", std::string _color = "~", bool Wireless = false, int _num = 0);


	// Getters & Setters:
	void setNumberOfKeys(int _num);
	int getNumOfKeys() const;

	//ToString op:
	operator std::string() const;

	//Connect func:
	void connect(Computer& comp);
};

