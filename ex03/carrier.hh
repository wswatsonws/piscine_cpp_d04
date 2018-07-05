#ifndef CARRIER_HPP
	#define CARRIER_HPP

#include "droid.hh"

class Carrier {
public:
	Carrier(std::string id = "");
	~Carrier();
	Carrier &operator~();
	std::string const &getId() const;
	void setId(std::string const &val);
	size_t getEnergy() const;
	void setEnergy(size_t val);
	size_t getAttack() const;
	size_t getToughness() const;
	size_t getSpeed() const;
	void setSpeed(size_t val);
	Carrier &operator<<(Droid*& droid);
	Carrier &operator>>(Droid*& droid);
	Droid const *&operator[](unsigned int const index);
	Droid const *operator[](unsigned int const index) const;
	bool operator()(int x, int y);
private:
	std::string Id;
	size_t Energy;
	size_t Attack;
	size_t Toughness;
	size_t Speed;
	Droid *Droids[5];
};

std::ostream	&operator<<(std::ostream& stream, Carrier const &carrier);

#endif
