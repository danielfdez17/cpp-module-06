#include "ScalarConverter.hpp"
#include "utils.hpp"
#include <limits.h>
#include <cmath>
#include <cstdlib>

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

bool	isPseudo(std::string s)
{
	return s == "nan" || s == "+inf" || s == "-inf"
		|| s == "nanf" || s == "+inff" || s == "-inff";
}

void	ScalarConverter::convert(std::string s)
{
	double	value;
	std::cout << YELLOW "Converting '" << s << "' ...\n" RESET;
	// ? if single non-digit character, convert directly to its ASCII value
	if (s.size() == 0 && !isdigit(s[0]))
	{
		value = static_cast<double>(s[0]);
	}
	else if (isPseudo(s))
	{
		value = std::strtod(s.c_str(), NULL);
	}
	else if (s.find('.') == std::string::npos)
	{
		value = static_cast<double>(std::atoi(s.c_str()));
	}
	else
	{
		value = std::strtod(s.c_str(), NULL);
	}
	ScalarConverter::toChar(value);
	ScalarConverter::toInt(value);
	ScalarConverter::toFloat(value);
	ScalarConverter::toDouble(value);
	std::cout << "\n";
}

void	ScalarConverter::toChar(double value)
{
	std::cout << BLUE << "char: " << RESET;
	if (std::isnan(value) || value < 0 || value > 127)
	{
		std::cout << RED "impossible\n" RESET;
	}
	else if (!isprint(static_cast<char>(value)))
	{
		std::cout << RED "Non displayable\n" RESET;
	}
	else
	{
		std::cout << "'" << static_cast<char>(value) << "'\n";
	}
}
void	ScalarConverter::toInt(double value)
{
	std::cout << MAGENTA << "int: " << RESET;
	if (std::isnan(value) || value > INT_MAX || value < INT_MIN)
	{
		std::cout << RED "impossible\n" RESET;
	}
	else
	{
		std::cout << static_cast<int>(value) << "\n";
	}
}
void	ScalarConverter::toFloat(double value)
{
	std::cout << CYAN << "float: " << RESET;
	if (std::isnan(value))
		std::cout << static_cast<float>(value) << "f\n";
	else
		std::cout << static_cast<float>(value) << ".0f\n";
}
void	ScalarConverter::toDouble(double value)
{
	std::cout << GREEN << "double: " << RESET;
	if (std::isnan(value))
		std::cout << static_cast<double>(value) << "\n";
	else
		std::cout << static_cast<double>(value) << ".0\n";
}

