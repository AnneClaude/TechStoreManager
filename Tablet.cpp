#include "Tablet.h"


//Construcor:
Tablet::Tablet(int pr, std::string manu, std::string clr, std::string _cpu, int ports, int _screenSize)
	: Item(pr, manu), PeripheralDevice(pr, manu, clr, true), Computer(pr, manu, _cpu, false, ports), screenSize(_screenSize)
{}

//Getters & Setters:
int Tablet::getScreenSize() const {
	return this->screenSize;
}

void Tablet::setScreenSize(int newSize) {
	this->screenSize = newSize;
}

// ToString op:
Tablet::operator std::string() const {
	return ("id " + std::to_string(this->getId()) + ": " + this->getManufacturer() + ", " + std::to_string(this->getPrice())
		+ "$, " + this->getColor() + ", " + this->getCpu() + ", Tablet with screen size: " + std::to_string(this->screenSize));
}
