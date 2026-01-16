#pragma once
#ifndef __SERIALIZER_HPP__
#define __SERIALIZER_HPP__

#include <string>
#include <iostream>
#include <cstdint>
#include "Data.hpp"

class Serializer {
private:
	Data *data;
	Serializer();
	Serializer(const Serializer& copy);
	Serializer& operator=(const Serializer& copy);
	~Serializer();

public:

	static uintptr_t	serialize(Data *ptr);
	static Data*		deserialize(uintptr_t raw);
};

#endif // __SERIALIZER_HPP__