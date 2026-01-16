#include "Serializer.hpp"
#include "utils.hpp"

int main(void)
{
	Data p = {0, 1, "potato", 23.0};
	uintptr_t raw;
	std::cout << Serializer::serialize(&p) << "\n";
	std::cout << Serializer::deserialize(raw) << "\n";
	return 0;
}