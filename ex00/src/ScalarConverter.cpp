#include "ScalarConverter.hpp"
#include "utils.hpp"
#include <limits.h>
#include <cmath>
#include <cstdlib>
#include <iomanip>

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

static bool	isPseudo(std::string s)
{
	return s == "nan" || s == "+inf" || s == "-inf"
		|| s == "nanf" || s == "+inff" || s == "-inff";
}

static int countPrecission(std::string s)
{
	size_t	dotPos = s.find('.');
	size_t	i;
	if (dotPos == std::string::npos)
		return 0;
	for (i = dotPos + 1; i < s.size() - 1; i++)
		if (!isdigit(s[i]))
		{
			if ((i != dotPos + 1))
				--i;
			break;
		}
	std::cout << YELLOW << "Precison: " << i - dotPos << "\n";
	return (int)(i - dotPos);
}

void	ScalarConverter::convert(std::string s)
{
	double	value;
	std::cout << YELLOW "Converting '" << s << "' ...\n" RESET;
	// ? if single non-digit character, convert directly to its ASCII value
	if (s.size() == 1 && !isdigit(s[0]))
	{
		value = static_cast<double>(s[0]);
	}
	// ? if this condition is not in the second place, the following condition will always be evaluated
	// ? and pseudo numbers casts/conversions will be lost
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
	ScalarConverter::toFloat(value, countPrecission(s));
	ScalarConverter::toDouble(value, countPrecission(s));
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
void	ScalarConverter::toFloat(double value, int precision)
{
	std::cout << CYAN << "float: " << RESET;
	int intValue = (int)value;
	double reminder = value - intValue;
	std::cout << std::fixed << std::setprecision(precision);
	if (reminder == 0.0f)
		std::cout << static_cast<float>(value) << ".0";
	else
		std::cout << static_cast<float>(value);
	std::cout << "f\n";
}
void	ScalarConverter::toDouble(double value, int precision)
{
	std::cout << GREEN << "double: " << RESET;
	int intValue = (int)value;
	double reminder = value - intValue;
	std::cout << std::fixed << std::setprecision(precision);
	if (reminder == 0.0)
		std::cout << static_cast<double>(value) << ".0\n";
	else
		std::cout << static_cast<double>(value) << "\n";
}

