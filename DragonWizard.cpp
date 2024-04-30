#include "DragonWizard.h"
#include <iostream>

DragonWizard::DragonWizard(const char* name, const char* nickname)
	: Creature(name), Dragon(name), Wizard(name, nickname)
{
}

void DragonWizard::print() const
{
	std::cout << "This creature is a DragonWizard named " << getName() << ", a.k.a. " << getNickname() << ' ';
	breatheFire();
	std::cout << ' ';
	castMagic();
}

void DragonWizard::breatheFire() const
{
	std::cout << "rraagghh!";
}

void DragonWizard::castMagic() const
{
	std::cout << "*zwing*";
}
