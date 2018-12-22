#ifndef __PLATYPUS_H__
#define __PLATYPUS_H__

#include "Mammal.hpp"

class Platypus : public Mammal
{
public:
	Platypus();
	~Platypus();
	Platypus(string gender, string name);
	Platypus(const Platypus& obj);
	Platypus& operator=(const Platypus& obj);

	void makeNoise();
	void injectVenom();
};

Platypus::Platypus()
{
	cout << "Platypus class default constructor" << endl;
	this->species = "Platypus";
}

Platypus::~Platypus()
{
	cout << "Platypus class destructor" << endl;
}

Platypus::Platypus(string gender, string name) : Mammal(gender, name, "four-legged")
{
	cout << "Platypus class user-defined constructor" << endl;
	this->species = "Platypus";
}

Platypus::Platypus(const Platypus& obj) : Mammal(obj)
{
	cout << "Platypus class copy constructor" << endl;
}

Platypus& Platypus::operator=(const Platypus& obj)
{
	Mammal::operator=(obj);
	cout << "Platypus class copy assignment operaotr" << endl;

	return *this;
}

void Platypus::makeNoise()
{
	cout << "This Platypus's voice is the same as the universal Platypus's voice" << endl;
}

void Platypus::injectVenom()
{
	cout << "The Platypus use a pair of spurs on their hind limbs to inject venom" << endl;
}

#endif /* __PLATYPUS_H__ */
