#ifndef DROID_H_
# define DROID_H_

#include <iostream>
#include <string>

class Droid
{
public:
	Droid(std::string const& id = "");
	Droid(Droid const& other);
	virtual ~Droid();

	Droid& operator=(Droid const& other);
	bool operator==(Droid const& other) const;
	bool operator!=(Droid const& other) const;

	std::string const& getId() const;
	void setId(std::string const& id);
	size_t getEnergy() const;
	void setEnergy(size_t const val);
	size_t getAttack() const;
	size_t getToughness() const;
	size_t getThoughness() const;
	std::string const* getStatus() const;
	void setStatus(std::string* val);
	void setStatus(std::string const& val);

private:
	std::string _id;
	size_t _energy;
	size_t const _attack;
	size_t const _thoughness;
	std::string* _status;
};

Droid& operator<<(Droid& droid, size_t& value);
std::ostream& operator<<(std::ostream& stream, Droid const& droid);

#endif
