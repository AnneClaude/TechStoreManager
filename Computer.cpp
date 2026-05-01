#include "Computer.h"

// Constructor:
Computer::Computer(int _price, std::string _manu, std::string _cpu, bool laptop, int ports)
	: Item(_price, _manu), cpu(_cpu), isALaptop(laptop), numOfPorts(ports) {
	this->numConnected = 0;
}


//Destructor
Computer::~Computer() {


	for (int i = 0; i < numConnected; ++i)
	{
		connected[i]->setConnectedComputer(nullptr);
	}
	this->connected.clear();
}


//Getters & Setters:

std::string Computer::getCpu() const {
	return this->cpu;
}

bool Computer::getIsALaptop() const {
	return this->isALaptop;
}

std::vector<PeripheralDevice*>& Computer::getConnected() {
	return this->connected;
}

int Computer::getNumConnected() const {
	return this->numConnected;
}

int Computer::getNumOfPorts() const {
	return this->numOfPorts;
}




void Computer::setCpu(std::string _cpu) {
	this->cpu = _cpu;
}

void Computer::setIsALaptop(bool laptop) {
	this->isALaptop = laptop;
}

void Computer::setNumConnected(int num) {
	this->numConnected = num;
}

// ToString op:
Computer::operator std::string() const
{
	std::string s;
	if (this->isALaptop) s = " Laptop, ";
	else s = " Desktop, ";
	return  ((this->Item::operator std::string()) + s + this->cpu);
}

// printConnected():
void Computer::printConnected() const {
	std::cout << "There are " << this->numConnected << " connections to " << std::string(*this) << std::endl;
	for (int i = 0; i < numConnected; i++) {
		std::cout << std::string(*connected[i]) << std::endl;
	}
}
