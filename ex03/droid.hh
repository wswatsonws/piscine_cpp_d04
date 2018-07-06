#ifndef DROID_H
#define DROID_H

#include    <string>
#include    "droidmemory.hh"

class Droid
{
private:

    std::string     Id;
    size_t          Energy;
    size_t const    Attack;
    size_t const    Toughness;
    std::string     *Status;
    DroidMemory     *BattleData;

public:

    Droid(std::string ID);
    Droid(Droid const & otherDroid);
    ~Droid();

    std::string     getId() const;
    size_t          getEnergy() const;
    size_t          getAttack() const;
    size_t          getToughness() const;
    std::string      *getStatus() const;
    DroidMemory     *getBattleData() const;

    void            setId(std::string const & ID);
    void            setEnergy(size_t const & energy);
    void            setStatus(std::string *status);
    void            setBattleData(DroidMemory *Memory);

    Droid &operator=(Droid const & Droid);
    bool operator!=(Droid const & Droid) const;
    bool operator==(Droid const & otherDroid) const;
    Droid & operator<<(size_t & EnergyStock);
    bool operator()(std::string const *task, size_t reqExp);
};

std::ostream& operator<<(std::ostream &out, Droid const & Droid);


#endif
