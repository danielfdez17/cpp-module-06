#include "ScalarConverter.hpp"
#include "colors.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << RED "Only one parameter is needed!\n" RESET;
		return 1;
	}
	ScalarConverter::convert(av[1]);
	return 0;
}