#include "Keyboard.h"


// Constructor:
Keyboard::Keyboard(int _price, std::string _manu, std::string _color, bool Wireless, int _num)
	:Item(_price, _manu), PeripheralDevice(_price, _manu, _color, Wireless), numberOfKeys(_num) { }


// Getters & Setters:
void Keyboard::setNumberOfKeys(int _num) {
	this->numberOfKeys = _num;
}

int Keyboard::getNumOfKeys() const {
	return this->numberOfKeys;
}


//Connect func:
void Keyboard::connect(Computer& comp)
{
	if (this->connectedComputer == &comp)
		return;
	std::cout << "Connecting a keyboard" << std::endl;
	PeripheralDevice::connect(comp);
}

//ToString op:
Keyboard::operator std::string() const
{
	return  (PeripheralDevice::operator std::string() + " Keyboard with " + std::to_string(this->numberOfKeys) + " keys");
}

