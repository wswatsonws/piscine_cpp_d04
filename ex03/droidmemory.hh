#ifndef DROIDMEM_HPP
#define DROIDMEM_HPP

#include <iostream>

class DroidMemory {
public:
	DroidMemory();
	~DroidMemory();
	size_t getFingerPrint() const;
	void setFingerPrint(size_t const value);
	size_t getExp() const;
	void setExp(size_t const value);
	DroidMemory &operator<<(DroidMemory const &other);
	DroidMemory &operator>>(DroidMemory &other) const;
	DroidMemory &operator+=(DroidMemory const &other);
	DroidMemory &operator+=(size_t const &val);
	DroidMemory operator+(DroidMemory const &other) const;
	DroidMemory operator+(size_t const val) const;
	bool operator==(DroidMemory const &other) const;
	bool operator!=(DroidMemory const &other) const;
	bool operator<(DroidMemory const &other) const;
	bool operator>(DroidMemory const &other) const;
	bool operator<=(DroidMemory const &other) const;
	bool operator>=(DroidMemory const &other) const;
private:
	size_t	FingerPrint;
	size_t	Exp;
};

std::ostream& operator<<(std::ostream& stream, DroidMemory const& memory);

#endif
