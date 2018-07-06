#ifndef CARRIER_H
#define CARRIER_H

#include            "droid.hh"

class Carrier
{
private:

    std::string     Id;
    size_t          Energy;
    size_t const    Attack;
    size_t const    Toughness;
    size_t          Speed;
    Droid           *Droids[5];
    size_t          getNbDroids() const;

public:

    Carrier(std::string Id);
    ~Carrier();

    std::string     getId() const;
    size_t          getEnergy() const;
    size_t          getSpeed() const;

    void            setId(std::string Id);
    void            setEnergy(size_t energy);
    void            setSpeed(size_t speed);

    void            displayCarrier() const;

    Carrier & operator<<(Droid *& BoardingDroid);
    Carrier & operator<<(size_t & EnergyStock);
    Carrier & operator>>(Droid *& BoardingDroid);
    Droid *&  operator[](size_t const & index);
    Droid * const &  operator[](size_t const & index) const;
    Carrier & operator~();
    bool    operator()(int const & posX, int const & posY);
};

std::ostream& operator<<(std::ostream &out, Carrier const & Carrier);

#endif
