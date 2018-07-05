#include "droidmemory.hh"

DroidMemory::DroidMemory()
	: FingerPrint(random()),
	  Exp(0)
{
}

DroidMemory::~DroidMemory()
{
}

size_t	DroidMemory::getFingerPrint() const
{
    return FingerPrint;
}

void	DroidMemory::setFingerPrint(size_t const value)
{
    FingerPrint = value;
}

size_t DroidMemory::getExp() const
{
    return Exp;
}

void DroidMemory::setExp(size_t const value)
{
    Exp = value;
}

DroidMemory	&DroidMemory::operator<<(DroidMemory const &other)
{
    setExp(getExp() + other.getExp());
    setFingerPrint(getFingerPrint() ^ other.getFingerPrint());
    return *this;
}

DroidMemory	&DroidMemory::operator>>(DroidMemory &other) const
{
    other.setExp(getExp() + other.getExp());
    other.setFingerPrint(getFingerPrint() ^ other.getFingerPrint());
    return other;
}

DroidMemory	&DroidMemory::operator+=(DroidMemory const &other)
{
    setExp(getExp() + other.getExp());
    setFingerPrint(getFingerPrint() ^ other.getFingerPrint());
    return *this;
}

DroidMemory& DroidMemory::operator+=(size_t const& val)
{
    setExp(getExp() + val);
    setFingerPrint(getFingerPrint() ^ val);
    return *this;
}

DroidMemory	DroidMemory::operator+(DroidMemory const &other) const
{
    DroidMemory	mem;

    mem.setExp(getExp() + other.getExp());
    mem.setFingerPrint(getFingerPrint() ^ other.getFingerPrint());
    return mem;
}

DroidMemory DroidMemory::operator+(size_t const val) const
{
    DroidMemory mem;

    mem.setExp(getExp() + val);
    mem.setFingerPrint(getFingerPrint() ^ val);
    return mem;
}

std::ostream &operator<<(std::ostream& stream, DroidMemory const &memory)
{
    stream << "DroidMemory '" << memory.getFingerPrint()
	   << "', " << memory.getExp();
    return stream;
}

bool	DroidMemory::operator==(DroidMemory const &other) const
{
	return (Exp == other.Exp) && (FingerPrint == other.FingerPrint);
}

bool	DroidMemory::operator!=(DroidMemory const &other) const
{
	return !((Exp == other.Exp) && (FingerPrint == other.FingerPrint));
}

bool	DroidMemory::operator<(DroidMemory const &other) const
{
	return Exp < other.Exp;
}

bool	DroidMemory::operator>(DroidMemory const &other) const
{
	return Exp > other.Exp;
}

bool	DroidMemory::operator<=(DroidMemory const &other) const
{
	return Exp <= other.Exp;
}

bool	DroidMemory::operator>=(DroidMemory const &other) const
{
	return Exp >= other.Exp;
}
