#pragma once
#include "Item.h"
#include <vector>
#include "PeripheralDevice.h"
#include "HWExceptions.h"

class PeripheralDevice;

class Computer : virtual public Item
{
private:
	std::string cpu;
	bool isALaptop;
	const int numOfPorts;
	std::vector<PeripheralDevice*> connected;
	int numConnected;

public:

	// Constructor:
	Computer(int _price = 0, std::string _manu = "~", std::string _cpu = "~", bool laptop = false, int ports = 0);

	// Destructor:
	virtual ~Computer();

	//Getters & Setters:
	std::string getCpu() const;
	bool getIsALaptop() const;
	std::vector<PeripheralDevice*>& getConnected();
	int getNumConnected() const;
	int getNumOfPorts() const;

	void setCpu(std::string _cpu);
	void setIsALaptop(bool laptop);
	void setNumConnected(int num);

	//ToString op:
	operator std::string() const;

	// printConnected():
	void printConnected() const;
};


