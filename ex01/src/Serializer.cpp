#include "Serializer.hpp"
#include "utils.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& copy) 
{
	if (this != &copy)
		*this = copy;
}

Serializer& Serializer::operator=(const Serializer& copy)
{
	if (this != &copy)
		*this = copy;
	return *this;
}

Serializer::~Serializer() {}

// ? The objective is to reinterpret the memory address, that's the reason why
// ? reinterpret_cast it is used and no any other one
uintptr_t	Serializer::serialize(Data *ptr)
{
	std::cout << BLUE << __func__ << ": " RESET;
	return reinterpret_cast<uintptr_t>(ptr);
}
Data*		Serializer::deserialize(uintptr_t raw)
{
	std::cout << CYAN << __func__ << ": " RESET;
	return reinterpret_cast<Data*>(raw);
}
