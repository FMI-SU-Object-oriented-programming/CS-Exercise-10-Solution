#ifndef DRAGON_WIZARD
#define DRAGON_WIZARD

#include "Dragon.h"
#include "Wizard.h"

class DragonWizard : public Dragon, public Wizard
{
public:
	DragonWizard(const char* name, const char* nickname);
	void print() const override;
	void breatheFire() const override;
	void castMagic() const override;
};

#endif // !DRAGON_WIZARD
