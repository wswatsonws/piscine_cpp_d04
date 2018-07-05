#include <iostream>
#include <string>
#include "carrier.hh"

Carrier::Carrier(std::string id)
	: Id(id),
	  Energy(300),
	  Attack(100),
	  Toughness(90)
{
	for (int i = 0; i < 5; ++i) {
		Droids[i] = nullptr;
	}
}

Carrier::~Carrier()
{
	for (int i = 0; i < 5; ++i) {
		if (Droids[i])
			delete Droids[i];
	}
}

Carrier	&Carrier::operator~()
{
	int j = 0;

	for (int i = 0; i < 5; ++i) {
		if (Droids[i])
			++j;
	}
	if (j == 0)
		Speed = 0;
	else
		Speed = 100 - (10 * j);
	return *this;
}

std::string const	&Carrier::getId() const
{
	return Id;
}

void	Carrier::setId(std::string const &val)
{
	Id = val;
}

size_t	Carrier::getEnergy() const
{
	return Energy;
}

void	Carrier::setEnergy(size_t val)
{
	if (val > 600)
		val = 600;
	Energy = val;
}

size_t	Carrier::getAttack() const
{
	return Attack;
}

size_t	Carrier::getToughness() const
{
	return Toughness;
}

size_t	Carrier::getSpeed() const
{
	return Speed;
}

void	Carrier::setSpeed(size_t val)
{
	Speed = val;
}

Carrier	&Carrier::operator<<(Droid *&droid)
{
	for (int i = 0; i < 5; ++i) {
		if (!Droids[i]) {
			Droids[i] = droid;
			droid = NULL;
			~(*this);
			return *this;
		}
	}
	return *this;
}

Carrier	&Carrier::operator>>(Droid*& droid)
{
	for (int i = 0; i < 5; ++i) {
		if (Droids[i]) {
			droid = Droids[i];
			Droids[i] = nullptr;
			~(*this);
			return *this;
		}
	}
	droid = nullptr;
	return *this;
}

Droid const	*&Carrier::operator[](unsigned int const index)
{
	return (Droid const *&)Droids[index];
}

Droid const	*Carrier::operator[](unsigned int const index) const
{
	return Droids[index];
}

bool Carrier::operator()(int x, int y)
{
	int j = 0;

	if (x < 0)
		x = -x;
	if (y < 0)
		y = -y;
	for (int i = 0; i < 5; ++i) {
		if (Droids[i])
			++j;
	}
	if (j == 0 || (unsigned int)((x + y) * (10 + j)) > Energy)
		return false;
	Energy -= (unsigned int)((x + y) * (10 + j));
	return true;
}

std::ostream	&operator<<(std::ostream &stream, Carrier const &carrier)
{
	stream << "Carrier '" << carrier.getId() << "' Droid(s) on-board:" << std::endl;
	for (int i = 0; i < 5; ++i) {
		stream << "[" << i << "] : ";
		if (carrier[i])
			stream << *carrier[i] << std::endl;
		else
			stream << "Free" << std::endl;
	}
	stream << "Speed : " << carrier.getSpeed()
	       << ", Energy " << carrier.getEnergy();
	return stream;
}

Carrier& operator<<(Carrier& carrier, size_t& value)
{
	if (carrier.getEnergy() + value > 600) {
		value -= 600 - carrier.getEnergy();
		carrier.setEnergy(600);
	} else {
		carrier.setEnergy(carrier.getEnergy() + value);
		value = 0;
	}
	return carrier;
}
