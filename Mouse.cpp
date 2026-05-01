#include "Mouse.h"



// Constructor:
Mouse::Mouse(int _price, std::string _manu, std::string _color, bool Wireless, int _dpi)
	:Item(_price, _manu), PeripheralDevice(_price, _manu, _color, Wireless), dpi(_dpi) { }


// Getters & Setters:
void Mouse::setDpi(int _dpi) {
	this->dpi = _dpi;
}

int Mouse::getDpi() const {
	return this->dpi;
}


//Connect func:
void Mouse::connect(Computer& comp)
{
	std::cout << "Connecting a mouse" << std::endl;
	PeripheralDevice::connect(comp);
}

//ToString op:
Mouse::operator std::string() const
{
	return (PeripheralDevice::operator std::string() + " Mouse with dpi : " + std::to_string(this->dpi));
}
