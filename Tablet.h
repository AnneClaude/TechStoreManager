#pragma once
#include "PeripheralDevice.h"
#include "Computer.h"

class Tablet : public PeripheralDevice, public Computer
{
	int screenSize;

public:

	//Constructor:
	Tablet(int pr = 0, std::string manu = "~", std::string clr = "~", std::string _cpu = "~", int ports = 0, int _screenSize = 0);

	//Getters & Setters:
	int getScreenSize() const;
	void setScreenSize(int newSize);

	// ToString op:
	operator std::string() const;


};
