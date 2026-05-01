#include "PeripheralDevice.h"
#include <typeinfo>

// Constructor:
PeripheralDevice::PeripheralDevice(int _price, std::string _manu, std::string _color, bool Wireless)
	: Item(_price, _manu), color(_color), isWireless(Wireless), connectedComputer(nullptr) { }

// Destructor:
PeripheralDevice::~PeripheralDevice() {
	disconnect();
}

// Getters & Setters:

Computer* PeripheralDevice::getConnectedComputer() const {
	return this->connectedComputer;
}

std::string PeripheralDevice::getColor() const {
	return this->color;
}

bool PeripheralDevice::getIsWireless() const {
	return this->isWireless;
}

void PeripheralDevice::setColor(std::string _color) {
	this->color = _color;
}

void PeripheralDevice::setIsWireless(bool _wireless) {
	this->isWireless = _wireless;
}

void PeripheralDevice::setConnectedComputer(Computer* comp) {
	this->connectedComputer = comp;
}


//ToString op:
PeripheralDevice::operator std::string() const {
	std::string s;
	if (this->isWireless) s = " Wireless, ";
	else s = " Wired, ";
	return  ((this->Item::operator std::string()) + s + this->color + ",");
}


//Connect/disconnect func(s):
void PeripheralDevice::connect(Computer& comp)
{
	std::cout << this->operator std::string() << " is connecting to computer: " << comp.operator std::string() << std::endl;

	std::vector<PeripheralDevice*>& arr = comp.getConnected();
	int num = comp.getNumConnected();

	// Checking cases that need to throw ConnectError() -

	if (this->connectedComputer) throw ConnectError();
	if (num == comp.getNumOfPorts())
		throw ConnectError();

	for (int i = 0; i < num; i++) {
		if (typeid(*this) == typeid(*arr[i]))
			throw ConnectError();
	}

	// do the connection:
	this->connectedComputer = &comp;
	arr.push_back(this);
	comp.setNumConnected(num + 1);
}

void PeripheralDevice::disconnect() {

	if (!this->connectedComputer) return;

	std::vector<PeripheralDevice*>& arr = this->connectedComputer->getConnected();

	int num = this->connectedComputer->getNumConnected();
	this->connectedComputer->setNumConnected(num - 1);

	std::vector<PeripheralDevice*>::iterator iter;

	// find the device in the vector and erase it:

	for (iter = arr.begin(); iter != arr.end(); ++iter) {
		if (*iter == this) {
			arr.erase(iter);
			this->connectedComputer = nullptr;
			return;
		}
	}
}
