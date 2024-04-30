#ifndef CREATURE
#define CREATURE

class Creature
{
public:
	Creature(const char* name);
	Creature(const Creature& other);
	Creature(Creature&& other) noexcept;
	Creature& operator=(const Creature& other);
	Creature& operator=(Creature&& other) noexcept;
	virtual ~Creature();

	virtual void print() const = 0;
	const char* getName() const;

private:
	void free();
	void copy(const Creature& other);
	void move(Creature&& other) noexcept;

	char* name;
};

#endif // !CREATURE
