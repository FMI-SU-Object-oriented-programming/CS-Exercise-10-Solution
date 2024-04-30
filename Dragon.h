#ifndef DRAGON
#define DRAGON
#include "Creature.h"

class Dragon : public virtual Creature
{
public:
	Dragon(const char* name);

	void print() const override;
	virtual void breatheFire() const;
};

#endif // !DRAGON


