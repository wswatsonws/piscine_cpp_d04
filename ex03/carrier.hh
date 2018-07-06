#ifndef CARRIER_H_
#define CARRIER_H_

#include <iostream>
#include <string>
#include "droid.hh"

class Carrier
{
public:
	Carrier(std::string const& id = "");
	virtual ~Carrier();

	std::string const& getId() const;
	void setId(std::string const& val);
	size_t getEnergy() const;
	void setEnergy(size_t val);
	size_t getAttack() const;
	size_t getToughness() const;
	size_t getSpeed() const;
	void setSpeed(size_t val);

	Carrier& operator<<(Droid*& droid);
	Carrier& operator>>(Droid*& droid);

	Droid const *& operator[](unsigned int const index);
	Droid const* operator[](unsigned int const index) const;

	Carrier &operator~();
	bool operator()(int x, int y);

private:
	std::string _id;
	size_t _energy;
	size_t const _attack;
	size_t const _toughness;
	size_t _speed;
	Droid* _droids[5];
};

std::ostream& operator<<(std::ostream& stream, Carrier const& carrier);

#endif
