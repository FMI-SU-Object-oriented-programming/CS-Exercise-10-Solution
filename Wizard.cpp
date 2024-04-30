#include "Wizard.h"
#include <iostream>
#include <stdexcept>
#include <cstring>
#pragma warning(disable:4996)

Wizard::Wizard(const char* name, const char* nickname)
    : Creature(name)
{
    if (!nickname)
        throw std::invalid_argument("nickname cannot be nullptr");

    this->nickname = new char[strlen(nickname) + 1];
    strcpy(this->nickname, nickname);
}

Wizard::Wizard(const Wizard& other)
    : Creature(other)
{
    copy(other);
}

Wizard::Wizard(Wizard&& other) noexcept
    : Creature(std::move(other))
{
    move(std::move(other));
}

Wizard& Wizard::operator=(const Wizard& other)
{
    if (this != &other)
    {
        Creature::operator=(other);
        free();
        copy(other);
    }
    return *this;
}

Wizard& Wizard::operator=(Wizard&& other) noexcept
{
    if (this != &other)
    {
        Creature::operator=(std::move(other));
        free();
        move(std::move(other));
    }
    return *this;
}

Wizard::~Wizard()
{
    free();
}

void Wizard::castMagic() const
{
    std::cout << "You shall not pass!\n";
}

void Wizard::print() const
{
    std::cout << "This creature is a Wizard named " << getName() << ", a.k.a. " << getNickname() << ". ";
    castMagic();
}

const char* Wizard::getNickname() const
{
    return nickname;
}

void Wizard::free()
{
    delete[] nickname;
}

void Wizard::copy(const Wizard& other)
{
    this->nickname = new char[strlen(other.nickname) + 1];
    strcpy(this->nickname, other.nickname);
}

void Wizard::move(Wizard&& other) noexcept
{
    this->nickname = other.nickname;
    other.nickname = nullptr;
}
