#ifndef DROIDMEMORY_H
# define DROIDMEMORY_H

#include    <iostream>
#include    <cstddef>

class DroidMemory
{
private:

    size_t      FingerPrint;
    size_t      Exp;

public:

    DroidMemory();
    DroidMemory(DroidMemory const & MemoryDump);
    ~DroidMemory();

    size_t      getFingerPrint() const;
    size_t      getExp() const;

    void        setFingerPrint(size_t fingerprint);
    void        setExp(size_t exp);

    DroidMemory & operator=(DroidMemory const & DroidMemory);
    DroidMemory & operator<<(DroidMemory const & Memory);
    DroidMemory & operator>>(DroidMemory & Memory);
    DroidMemory & operator+=(DroidMemory const & Memory);
    DroidMemory & operator+=(size_t value);
    DroidMemory & operator+(DroidMemory const & Memory);
    DroidMemory & operator+(size_t value);

    bool    operator==(DroidMemory const & Memory) const;
    bool    operator!=(DroidMemory const & Memory) const;
    bool    operator<(DroidMemory const & Memory) const;
    bool    operator<(size_t value) const;
    bool    operator>(DroidMemory const & Memory) const;
    bool    operator>(size_t value) const;
    bool    operator<=(DroidMemory const & Memory) const;
    bool    operator<=(size_t value) const;
    bool    operator>=(DroidMemory const & Memory) const;
    bool    operator>=(size_t value) const;
};

std::ostream& operator<<(std::ostream &out, DroidMemory const & DroidMemory);

#endif
