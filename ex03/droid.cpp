#include    <iostream>
#include    "droid.hh"

Droid::Droid(std::string ID) : Id(ID), Energy(50), Attack(25), Toughness(15)
{
    this->Status = new std::string("Standing by");
    std::cout << "Droid '" << this->Id << "' Activated" << std::endl;
    this->BattleData = new DroidMemory();
}

Droid::Droid(Droid const & otherDroid) : Id(otherDroid.Id), Energy(50), Attack(otherDroid.Attack), Toughness(otherDroid.Toughness)
{
    this->Status = new std::string(otherDroid.Status->c_str());
    std::cout << "Droid '" << this->Id << "' Activated, Memory Dumped" << std::endl;
    this->BattleData = new DroidMemory(*otherDroid.BattleData);
}

Droid::~Droid()
{
    std::cout << "Droid '" << this->Id << "' Destroyed" << std::endl;
    delete(this->Status);
    delete(this->BattleData);
}

std::string Droid::getId() const
{
    return this->Id;
}

size_t      Droid::getEnergy() const
{
    return this->Energy;
}

size_t      Droid::getAttack() const
{
    return this->Attack;
}

size_t      Droid::getToughness() const
{
    return this->Toughness;
}

std::string *   Droid::getStatus() const
{
    return this->Status;
}

DroidMemory *   Droid::getBattleData() const
{
    return this->BattleData;
}

void            Droid::setId(std::string const & ID)
{
    this->Id = ID;
}

void            Droid::setEnergy(size_t const & energy)
{
    if (energy > 100) {
        this->Energy = 100;
    }
    else {
        this->Energy = energy;
    }
}

void            Droid::setStatus(std::string *status)
{
    delete this->Status;
    this->Status = status;
}

void            Droid::setBattleData(DroidMemory *Memory)
{
    delete this->BattleData;
    this->BattleData = Memory;
}

Droid &         Droid::operator=(Droid const & Droid)
{
    this->Id = Droid.Id;
    delete this->Status;
    this->Status = new std::string (Droid.Status->c_str());
    return *this;
}

bool            Droid::operator!=(Droid const & otherDroid) const
{
    return !Droid::operator==(otherDroid);
}

bool            Droid::operator==(Droid const & otherDroid) const
{
    if (*this->Status != *otherDroid.Status) {
        return false;
    }
    return true;
}

Droid &          Droid::operator<<(size_t & EnergyStock)
{
    size_t      delta = 100 - this->Energy;
    if (EnergyStock < delta) {
        delta = EnergyStock;
    }
    this->Energy += delta;
    EnergyStock -= delta;
    return *this;
}

bool            Droid::operator()(std::string const *task, size_t reqExp)
{
    if (this->Energy <= 10) {
        this->setStatus(new std::string("Battery Low"));
        this->Energy = 0;
        return false;
    }
    this->Energy -= 10;
    if (this->BattleData->getExp() >= reqExp) {
        this->setStatus(new std::string(*task + " - Completed!"));
        this->BattleData->setExp(this->BattleData->getExp() + (reqExp / 2));
        return true;
    }
    this->setStatus(new std::string(*task + " - Failed!"));
    this->BattleData->setExp(this->BattleData->getExp() + reqExp);
    return false;
}

std::ostream & operator<<(std::ostream &out, Droid const & Droid)
{
    return out << "Droid '" << Droid.getId() << "', " << *Droid.getStatus() << ", " << Droid.getEnergy();
}
