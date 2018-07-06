#include <cstdlib>
#include "droidmemory.hh"

DroidMemory::DroidMemory()
{
    this->Exp = 0;
    this->FingerPrint = random();
}

DroidMemory::DroidMemory(DroidMemory const & MemoryDump)
{
    this->Exp = MemoryDump.Exp;
    this->FingerPrint = MemoryDump.FingerPrint;
}

DroidMemory::~DroidMemory()
{

}

size_t      DroidMemory::getFingerPrint() const
{
    return this->FingerPrint;
}

size_t      DroidMemory::getExp() const
{
    return this->Exp;
}

void       DroidMemory::setFingerPrint(size_t fingerprint)
{
    this->FingerPrint = fingerprint;
}

void       DroidMemory::setExp(size_t exp)
{
    this->Exp = exp;
}

DroidMemory & DroidMemory::operator=(DroidMemory const & Memory)
{
    this->FingerPrint = Memory.FingerPrint;
    this->Exp = Memory.Exp;
    return *this;
}

DroidMemory & DroidMemory::operator<<(DroidMemory const & Memory)
{
    this->Exp += Memory.Exp;
    this->FingerPrint = (Memory.FingerPrint ^ this->FingerPrint);
    return *this;
}

DroidMemory & DroidMemory::operator>>(DroidMemory & Memory)
{
    Memory.Exp += this->Exp;
    Memory.FingerPrint = (this->FingerPrint ^ Memory.FingerPrint);
    return *this;
}

DroidMemory & DroidMemory::operator+=(DroidMemory const & Memory)
{
    return DroidMemory::operator<<(Memory);
}

DroidMemory & DroidMemory::operator+=(size_t value)
{
    this->Exp += value;
    this->FingerPrint = (this->FingerPrint ^ value);
    return *this;
}

DroidMemory & DroidMemory::operator+(DroidMemory const & Memory)
{
    DroidMemory *NewMemory = new DroidMemory;
    NewMemory->Exp = this->Exp + Memory.Exp;
    NewMemory->FingerPrint = (this->FingerPrint ^ Memory.FingerPrint);
    return *NewMemory;
}

DroidMemory & DroidMemory::operator+(size_t value)
{
    DroidMemory *NewMemory = new DroidMemory;

    NewMemory->Exp = this->Exp + value;
    NewMemory->FingerPrint = (FingerPrint ^ value);
    return *NewMemory;
}

std::ostream& operator<<(std::ostream &out, DroidMemory const & DroidMemory)
{
    return out << "DroidMemory '" << DroidMemory.getFingerPrint() << "', " << DroidMemory.getExp();
}

bool    DroidMemory::operator==(DroidMemory const & Memory) const
{
    if ((this->Exp != Memory.Exp) || (this->FingerPrint != Memory.FingerPrint)) {
        return false;
    }
    return true;
}

bool    DroidMemory::operator!=(DroidMemory const & Memory) const
{
    return !DroidMemory::operator==(Memory);
}

bool    DroidMemory::operator<(DroidMemory const & Memory) const
{
    return this->Exp < Memory.Exp;
}

bool    DroidMemory::operator<(size_t value) const
{
    return this->Exp < value;
}

bool    DroidMemory::operator>(DroidMemory const & Memory) const
{
    return this->Exp > Memory.Exp;
}

bool    DroidMemory::operator>(size_t value) const
{
    return this->Exp > value;
}

bool    DroidMemory::operator<=(DroidMemory const & Memory) const
{
    return this->Exp <= Memory.Exp;
}

bool    DroidMemory::operator<=(size_t value) const
{
    return this->Exp <= value;
}

bool    DroidMemory::operator>=(DroidMemory const & Memory) const
{
    return this->Exp >= Memory.Exp;
}

bool    DroidMemory::operator>=(size_t value) const
{
    return this->Exp >= value;
}
