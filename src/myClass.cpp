#include "myClass.h"

MyClass::MyClass(int pin_number) {
   this->_pin_number = pin_number;
   this->_light_on = false;

   pinMode(this->_pin_number, OUTPUT);
   digitalWrite(this->_pin_number, LOW);
}

void MyClass::toggle() {
   _light_on = !_light_on;

   digitalWrite(_pin_number, _light_on ? HIGH : LOW);
}

bool MyClass::isOn() {
   return _light_on;
}


MyClass::~MyClass() {
   digitalWrite(_pin_number, LOW); 
}
