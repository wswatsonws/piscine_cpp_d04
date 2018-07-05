#ifndef DROID_HPP
#define DROID_HPP

#include <string>
#include <iostream>
#include "droidmemory.hh"

class Droid {
public:
	Droid(std::string id);
	Droid(Droid const &other);
	~Droid();
	Droid &operator=(Droid const &other);
	std::string const &getId() const;
	size_t getEnergy() const;
	size_t getAttack() const;
	size_t getToughness() const;
	std::string const *getStatus() const;
	void setId(std::string next);
	void setEnergy(size_t next);
	void setStatus(std::string *next);
	bool operator==(Droid const &other) const;
	bool operator!=(Droid const &other) const;
	Droid	&operator<<(size_t &energy);
	DroidMemory const *getBattleData() const;
	DroidMemory *getBattleData();
	void setBattleData(DroidMemory *mem);
	bool operator()(const std::string *task, size_t exp);
private:
	std::string	Id;
	size_t		Energy;
	const size_t	Attack;
	const size_t	Toughness;
	std::string	*Status;
	DroidMemory	*BattleData;
};

std::ostream &operator<<(std::ostream &stream, Droid const &droid);

#endif
