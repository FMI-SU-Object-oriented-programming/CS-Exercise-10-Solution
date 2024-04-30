#ifndef WIZARD
#define WIZARD

#include "Creature.h"

class Wizard : public virtual Creature
{
public:
	Wizard(const char* name, const char* nickname);
	Wizard(const Wizard& other);
	Wizard(Wizard&& other) noexcept;
	Wizard& operator=(const Wizard& other);
	Wizard& operator=(Wizard&& other) noexcept;
	virtual ~Wizard();

	virtual void castMagic() const;

	void print() const override;
	const char* getNickname() const;

private:
	void free();
	void copy(const Wizard& other);
	void move(Wizard&& other) noexcept;

	char* nickname;
};

#endif