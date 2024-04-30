#include "Dragon.h"
#include <iostream>

Dragon::Dragon(const char* name)
	: Creature(name)
{
}

void Dragon::print() const
{
	std::cout << "This creature is a Dragon named " << getName() << ". ";
	breatheFire();
}

void Dragon::breatheFire() const
{
	std::cout << "RRAAGGHHH!!!\n";
}
