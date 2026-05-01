#pragma once
#include "PeripheralDevice.h"

class Mouse : public PeripheralDevice
{
private:
	int dpi;

public:

	// Constructor:
	Mouse(int _price = 0, std::string _manu = "~", std::string _color = "~", bool Wireless = false, int _dpi = 0);
	// Getters & Setters:
	void setDpi(int _dpi);
	int getDpi() const;

	//ToString op:
	operator std::string() const;

	//Connect func:
	void connect(Computer& comp);
};
