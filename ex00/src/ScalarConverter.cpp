#include "ScalarConverter.hpp"
#include "colors.hpp"
#include <cctype>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& copy) 
{
	if (this != &copy)
		*this = copy;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy)
{
	if (this != &copy)
		*this = copy;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

void	ScalarConverter::convert(std::string s)
{
	std::cout << YELLOW "Converting '" << s << "' ...\n" RESET;
	ScalarConverter::toChar(s);
	ScalarConverter::toInt(s);
	ScalarConverter::toFloat(s);
	ScalarConverter::toDouble(s);
	std::cout << "\n";
}

void	ScalarConverter::toChar(std::string s)
{
	(void)s;
	std::cout << BLUE << __func__ << ": " << RESET;
	if (s.size() == 1 && isprint(static_cast<char>(s[0])))
	{
		std::cout << s[0] << "\n";
	}
	else
	{

		std::cout << RED "Unimplemented method\n" RESET;
	}
}
void	ScalarConverter::toInt(std::string s)
{
	(void)s;
	std::cout << MAGENTA << __func__ << ": " << RESET;
	std::cout << RED "Unimplemented method\n" RESET;
}
void	ScalarConverter::toFloat(std::string s)
{
	(void)s;
	std::cout << CYAN << __func__ << ": " << RESET;
	std::cout << RED "Unimplemented method\n" RESET;
}
void	ScalarConverter::toDouble(std::string s)
{
	(void)s;
	std::cout << BLUE << __func__ << ": " << RESET;
	std::cout << RED "Unimplemented method\n" RESET;
}

