#include <cstddef>
#include <string>
#include <iostream>
#include "droid.hh"
#include "droidmemory.hh"

Droid::Droid(std::string id)
	: Id(id),
	  Energy(50),
	  Attack(25),
	  Toughness(15),
	  Status(nullptr),
	  BattleData(new DroidMemory())
{
	Status = new std::string("Standing by");
	std::cout << "Droid '" << Id << "' Activated\n";
}

Droid::Droid(Droid const &other)
	: Id(other.Id),
	  Energy(other.Energy),
	  Attack(other.Attack),
	  Toughness(other.Toughness),
	  Status(nullptr),
	  BattleData(nullptr)
{
	if (other.Status) {
		if (Status)
			delete Status;
		Status = new std::string(*other.Status);
	} else if (Status) {
		delete Status;
		Status = nullptr;
	}
	BattleData = new DroidMemory(*other.BattleData);
	std::cout << "Droid '" << Id << "' Activated, Memory Dumped\n";
}

Droid::~Droid()
{
	if (Status)
		delete Status;
	std::cout << "Droid '" << Id << "' Destroyed\n";
}

Droid	&Droid::operator=(Droid const &other)
{
	if (this == &other)
	    return (*this);
	Id = other.Id;
	if (other.Status) {
		if (Status)
			*Status = *other.Status;
		else
			Status = new std::string(*other.Status);
	} else if (Status) {
		delete Status;
		Status = nullptr;
	}
	if (BattleData)
		delete BattleData;
	BattleData = new DroidMemory(*other.BattleData);
	return *this;
}

std::string const	&Droid::getId() const
{
	return Id;
}

size_t	Droid::getEnergy() const
{
	return Energy;
}

size_t	Droid::getAttack() const
{
	return Attack;
}

size_t	Droid::getToughness() const
{
	return Toughness;
}

std::string const	*Droid::getStatus() const
{
	return Status;
}

void	Droid::setId(std::string next)
{
	Id = next;
}

void	Droid::setEnergy(size_t next)
{
	if (next > 100)
		Energy = 100;
	else
		Energy = next;
}

void	Droid::setStatus(std::string *next)
{
	if (Status)
		delete Status;
	Status = next;
}

bool	Droid::operator==(Droid const &other) const
{
	return *Status == *(other.Status);
}

bool	Droid::operator!=(Droid const &other) const
{
	return !(*Status == *(other.Status));
}

Droid	&Droid::operator<<(size_t &energy)
{
	if (energy + Energy > 100) {
		energy -= (100 - Energy);
		setEnergy(100);
	} else {
		Energy += energy;
		energy = 0;
	}
	return *this;
}

std::ostream	&operator<<(std::ostream &stream, Droid const &droid)
{
	stream << "Droid '" << droid.getId()
	       << "', " << (droid.getStatus() ? *(droid.getStatus()) : "")
	       << ", " << droid.getEnergy();
	return stream;
}

DroidMemory const	*Droid::getBattleData() const
{
	return BattleData;
}

DroidMemory	*Droid::getBattleData()
{
	return BattleData;
}

void	Droid::setBattleData(DroidMemory *mem)
{
	BattleData = mem;
}

bool	Droid::operator()(const std::string *task, size_t exp)
{
	if (!task || !BattleData)
		return false;
	if (!Status)
		Status = new std::string("");
	if (Energy <= 10)
	{
		*Status = "Battery Low";
		Energy = 0;
		return false;
	}
	Energy -= 10;
	if (BattleData->getExp() < exp){
		*Status = *task + " - Failed!";
		BattleData->setExp(BattleData->getExp() + exp);
		return false;
	}
	*Status = *task + " - Completed!";
	BattleData->setExp(BattleData->getExp() + (exp / 2));
	return true;
}
