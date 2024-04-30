#include <iostream>
#include "DragonWizard.h"

void printCreature(const Creature* creature)
{
    creature->print();
}

int main()
{
    Dragon toothless("Toothless");
    Wizard gandalf("Gandalf", "The old man");
    DragonWizard toothless_gandalf("Toothless Gandalf", "The old dragon man");

    // one implementation of 'printCreature' (no templates)
    printCreature(&toothless);
    std::cout << '\n';
    printCreature(&gandalf);
    std::cout << '\n';
    printCreature(&toothless_gandalf);
    return 0;
}