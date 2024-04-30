#include "Creature.h"
#include <stdexcept>
#include <cstring>
#pragma warning(disable:4996)

Creature::Creature(const char* name)
{
    if (!name)
        throw std::invalid_argument("name cannot be nullptr");

    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

Creature::Creature(const Creature& other)
{
    copy(other);
}

Creature::Creature(Creature&& other) noexcept
{
    move(std::move(other));
}

Creature& Creature::operator=(const Creature& other)
{
    if (this != &other)
    {
        free();
        copy(other);
    }
    return *this;
}

Creature& Creature::operator=(Creature&& other) noexcept
{
    if (this != &other)
    {
        free();
        move(std::move(other));
    }
    return *this;
}

Creature::~Creature()
{
    free();
}

const char* Creature::getName() const
{
    return name;
}

void Creature::free()
{
    delete[] name;
}

void Creature::copy(const Creature& other)
{
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
}

void Creature::move(Creature&& other) noexcept
{
    this->name = other.name;
    other.name = nullptr;
}
