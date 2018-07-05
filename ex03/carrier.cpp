#include "carrier.hh"

Carrier::Carrier(std::string const& id) : _id(id), _energy(300), _attack(100),
    _toughness(90), _speed(0)
{
    for (int i = 0; i < 5; ++i)
        _droids[i] = NULL;
}

Carrier::~Carrier()
{
    for (int i = 0; i < 5; ++i)
        if (_droids[i])
            delete _droids[i];
}

std::string const& Carrier::getId() const
{
    return _id;
}

void Carrier::setId(std::string const& val)
{
    _id = val;
}

size_t Carrier::getEnergy() const
{
    return _energy;
}

void Carrier::setEnergy(size_t val)
{
    if (val > 600)
        val = 600;
    _energy = val;
}

size_t Carrier::getAttack() const
{
    return _attack;
}

size_t Carrier::getToughness() const
{
    return _toughness;
}

size_t Carrier::getSpeed() const
{
    return _speed;
}

void Carrier::setSpeed(size_t val)
{
    _speed = val;
}

Carrier& Carrier::operator<<(Droid*& droid)
{
    for (int i = 0; i < 5; ++i)
        if (!_droids[i])
        {
            _droids[i] = droid;
            droid = NULL;
            ~(*this);
            return *this;
        }
    return *this;
}

Carrier& Carrier::operator>>(Droid*& droid)
{
    for (int i = 0; i < 5; ++i)
        if (_droids[i])
        {
            droid = _droids[i];
            _droids[i] = NULL;
            ~(*this);
            return *this;
        }
    droid = NULL;
    return *this;
}

Droid const*& Carrier::operator[](unsigned int const index)
{
    return (Droid const*&)_droids[index];
}

Droid const* Carrier::operator[](unsigned int const index) const
{
    return _droids[index];
}

Carrier& Carrier::operator~()
{
    int count = 0;
    for (int i = 0; i < 5; ++i)
        if (_droids[i])
            ++count;

    if (count == 0)
        _speed = 0;
    else
        _speed = 100 - (10 * count);
    return *this;
}
    
bool Carrier::operator()(int x, int y)
{
    if (x < 0)
        x *= -1;
    if (y < 0)
        y *= -1;
    int count = 0;
    for (int i = 0; i < 5; ++i)
        if (_droids[i])
            ++count;
    if (count == 0 || (unsigned int)((x + y) * (10 + count)) > _energy)
        return false;
    _energy -= (unsigned int)((x + y) * (10 + count));
    return true;
}

std::ostream& operator<<(std::ostream& stream, Carrier const& carrier)
{
    stream << "Carrier '" << carrier.getId() << "' Droid(s) on-board:" << std::endl;
    for (int i = 0; i < 5; ++i)
    {
        stream << "[" << i << "] : ";
        if (carrier[i])
            stream << *carrier[i] << std::endl;
        else
            stream << "Free" << std::endl;
    }
    stream << "Speed : " << carrier.getSpeed() << ", Energy " << carrier.getEnergy();
    return stream;
}

Carrier& operator<<(Carrier& carrier, size_t& value)
{
    if (carrier.getEnergy() + value > 600)
    {
        value -= 600 - carrier.getEnergy();
        carrier.setEnergy(600);
    }
    else
    {
        carrier.setEnergy(carrier.getEnergy() + value);
        value = 0;
    }
    return carrier;
}
