#include    <cstdlib>
#include "carrier.hh"

Carrier::Carrier(std::string Id) : Id(""), Energy(300), Attack(100), Toughness(90), Droids()
{
    this->Id = Id;
    this->Speed = 0;
}

Carrier::~Carrier()
{
    for (size_t i = 0 ; i < 5 ; i++) {
        if (this->Droids[i]) {
            delete this->Droids[i];
        }
    }
}

std::string Carrier::getId() const
{
    return this->Id;
}

size_t Carrier::getEnergy() const
{
    return this->Energy;
}

size_t Carrier::getSpeed() const
{
    return this->Speed;
}

void        Carrier::setId(std::string Id)
{
    this->Id = Id;
}

void        Carrier::setEnergy(size_t energy)
{
    this->Energy = energy;
}

void        Carrier::setSpeed(size_t speed)
{
    this->Speed = speed;
}

size_t      Carrier::getNbDroids() const
{
    size_t      nbDroids = 0;

    for (size_t i = 0 ; i < 5 ; i++) {
        if (this->Droids[i]) {
            nbDroids += 1;
        }
    }
    return nbDroids;
}

void        Carrier::displayCarrier() const
{
    std::cout << "Carrier '" << this->Id << "' Droid(s) on-board:" << std::endl;
    for (size_t i = 0 ; i < 5 ; i++) {
        std::cout << "[" << i << "] : ";
        if (this->Droids[i]) {
            std::cout << *this->Droids[i] << std::endl;
        }
        else {
            std::cout << "Free" << std::endl;
        }
    }
    std::cout << "Speed : " << this->getSpeed() << ", Energy " << this->getEnergy();
}

Carrier & Carrier::operator<<(Droid *& BoardingDroid)
{
    for (size_t i = 0 ; i < 5 ; i++) {
        if (this->Droids[i] == NULL) {
            this->Droids[i] = BoardingDroid;
            BoardingDroid = NULL;
            this->Speed = 100 - (this->getNbDroids() * 10);
            break;
        }
    }
    return *this;
}

Carrier & Carrier::operator<<(size_t & EnergyStock)
{
    size_t      delta = 600 - this->Energy;

    if (EnergyStock < delta) {
        delta = EnergyStock;
    }
    this->Energy += delta;
    EnergyStock -= delta;
    return *this;
}

Carrier & Carrier::operator>>(Droid *& BoardingDroid)
{
    for (size_t i = 0 ; i < 5 ; i++) {
        if (this->Droids[i] != NULL) {
            BoardingDroid = this->Droids[i];
            this->Droids[i] = NULL;
            this->Speed += 10;
            if (this->getNbDroids() == 0) {
                this->Speed = 0;
            }
            break;
        }
    }
    return *this;
}

Droid *& Carrier::operator[](size_t const & index)
{
    return this->Droids[index];
}

Droid * const & Carrier::operator[](size_t const & index) const
{
    return this->Droids[index];
}

Carrier & Carrier::operator~()
{
    if (this->getNbDroids() == 0) {
        this->Speed = 0;
    }
    else {
        this->Speed = 100 - (10 * this->getNbDroids());
;    }
    return *this;
}

bool        Carrier::operator()(int const & posX, int const & posY)
{
    size_t      nbDroids = 0;
    size_t         energyCost;

    for (size_t i = 0 ; i < 5 ; i++) {
        if (this->Droids[i]) {
            nbDroids += 1;
        }
    }

    energyCost = (abs(posX) + abs(posY)) * (10 + nbDroids);

    if (this->Speed == 0 || this->Energy < energyCost) {
        return false;
    }
    this->setEnergy(this->getEnergy() - energyCost);
    return true;
}

std::ostream& operator<<(std::ostream &out, Carrier const & Carrier)
{
    Carrier.displayCarrier();
    return out;
}
