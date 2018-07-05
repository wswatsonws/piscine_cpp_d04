/*
** droid.hh for ex00 in /home/fest/Epitech/Piscine_tek2/piscine_cpp_d08-2016-ginter_m/ex00
**
** Made by maxime ginters
** Login  <ginter_m@epitech.eu>
**
** Started on  Wed Jan 16 09:28:08 2013 maxime ginters
** Last update Wed Jan 16 22:52:54 2013 maxime ginters
*/

#ifndef DROID_H_
# define DROID_H_

#include <iostream>
#include <string>
#include "droidmemory.hh"

class Droid
{
public:
    explicit Droid(std::string const& id);
    explicit Droid(Droid const& other);
    virtual ~Droid();

    Droid& operator=(Droid const& other);
    bool operator==(Droid const& other) const;
    bool operator!=(Droid const& other) const;

    std::string const& getId() const;
    void setId(std::string const& id);
    size_t getEnergy() const;
    void setEnergy(size_t const val);
    size_t getAttack() const;
    size_t getThoughness() const;
    size_t getToughness() const;
    std::string const* getStatus() const;
    void setStatus(std::string* val);
    void setStatus(std::string const& val);

    DroidMemory const* getBattleData() const;
    DroidMemory* getBattleData();
    void setBattleData(DroidMemory* mem);

private:
    std::string _id;
    size_t _energy;
    size_t const _attack;
    size_t const _thoughness;
    std::string* _status;
    DroidMemory* _battleData;
};

Droid& operator<<(Droid& droid, size_t& value);
std::ostream& operator<<(std::ostream& stream, Droid const& droid);


#endif /* !DROID_H_ */
