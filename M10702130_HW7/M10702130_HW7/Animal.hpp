#ifndef __ANIMAL_H__
#define __ANIMAL_H__

#include <iostream>
#include <string>

using namespace std;

class Animal
{
public:
	Animal();
	~Animal();
	Animal(string gender, string name);
	Animal(const Animal& obj);
	Animal& operator=(const Animal& obj);

	virtual void makeNoise();
	virtual void print();

	string species;
	string gender;
	string name;
};

Animal::Animal()
{
	cout << "Animal class default constructor" << endl;
	this->species = "Animal";
	this->gender = "";
	this->name = "";
}

Animal::~Animal()
{
	cout << "Animal class destructor" << endl;
}

Animal::Animal(string gender, string name)
{
	cout << "Animal class user-defined constructor" << endl;
	this->species = "Animal";
	this->gender = gender;
	this->name = name;
}

Animal::Animal(const Animal& obj)
{
	cout << "Animal class copy constructor" << endl;
	this->species = obj.species;
	this->gender = obj.gender;
	this->name = obj.name;
}

Animal& Animal::operator=(const Animal& obj)
{
	cout << "Animal class copy assignment operator" << endl;
	this->species = obj.species;
	this->gender = obj.gender;
	this->name = obj.name;

	return *this;
}

void Animal::makeNoise()
{
	cout << "This animal is very silent" << endl;
}

void Animal::print()
{
	cout << "The following shows this " << this->species << " information" << endl;
	cout << "Its name is called " << this->name << " and its gender is ";

	if (this->gender == "F") {
		cout << "Female" << endl;
	} else {
		cout << "Male" << endl;
	}
}

#endif /* __ANIMAL_H__ */
