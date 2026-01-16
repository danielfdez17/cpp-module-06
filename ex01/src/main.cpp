#include "Serializer.hpp"
#include "utils.hpp"
// #include <stdio.h>
int main(void)
{
	Data p = {0, 1, "potato", 23.0};
	Data *aux;
	std::cout << GREEN << &p << "\n" RESET;
	std::cout << YELLOW << reinterpret_cast<uintptr_t>(&p) << "\n" RESET;
	// printf("%llu\n", (long long)&p);
	uintptr_t raw = Serializer::serialize(&p); 
	std::cout << YELLOW << raw << "\n" RESET;
	aux = Serializer::deserialize(raw);
	std::cout << GREEN << aux << "\n" RESET;
	return 0;
}