#include "ScalarConverter.hpp"
#include "utils.hpp"
#include <limits.h>
#include <cmath>
#include <cstdlib>
#include <iomanip>

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	if (this != &copy)
		*this = copy;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &copy)
{
	if (this != &copy)
		*this = copy;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

static bool	isPseudoDouble(std::string s)
{
	return s == "nan" || s == "+inf" || s == "-inf";
}

static bool	isPseudoFloat(std::string s)
{
	return s == "nanf" || s == "+inff" || s == "-inff";
}

static bool isPseudo(std::string s)
{
	return isPseudoDouble(s) || isPseudoFloat(s);
}

int countPrecission(std::string s, size_t dotPos)
{
	size_t i;
	if (dotPos == std::string::npos)
		return 0;
	for (i = dotPos + 1; i < s.size(); i++)
		if (!isdigit(s[i]))
			break;
	return (int)(i - dotPos - 1);
}

void ScalarConverter::convert(std::string s)
{
	size_t size = s.size();
	size_t pos;
	if (size == 0)
	{
		std::cout << RED "The string should have at least one character\n" RESET;
		return;
	}
	std::cout << YELLOW "Converting '" << s << "' ...\n" RESET;
	// ? if single non-digit character, convert directly to its ASCII value
	pos = s.find('.');
	if (s.size() == 1)
	{
		ScalarConverter::fromChar((s[0]));
	}
	else if (isPseudo(s))
	{
		if (isPseudoDouble(s))
			ScalarConverter::fromDouble(std::strtod(s.c_str(), NULL), 0);
		else if (isPseudoFloat(s))
			ScalarConverter::fromFloat(std::strtof(s.c_str(), NULL), 0);
	}
	else if (pos != std::string::npos)
	{
		if (pos + 1 < size && s[pos + 1] == 'f')
			ScalarConverter::fromFloat(std::strtof(s.c_str(), NULL), countPrecission(s, pos));
		else
			ScalarConverter::fromDouble(std::strtod(s.c_str(), NULL), countPrecission(s, pos));
	}
	else if (pos == std::string::npos)
		ScalarConverter::fromInt(std::atoi(s.c_str()));
	std::cout << "\n";
}

void ScalarConverter::toChar(double value)
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
void ScalarConverter::toInt(double value)
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
void ScalarConverter::toFloat(double value, int precision)
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
void ScalarConverter::toDouble(double value, int precision)
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

void ScalarConverter::fromChar(char c)
{
	{
		std::cout << BLUE << "char: " << RESET;
		if (isdigit(c))
			c = c - '0';
		if (c <= 0 || c >= 127)
			std::cout << IMPOSSIBLE "\n" RESET;
		else if (!isprint(c))
			std::cout << NON_DISPLAYABLE "\n" RESET;
		else
			std::cout << "'" << c << "'\n";
	}
	{
		std::cout << MAGENTA << "int: " << RESET << static_cast<int>(c) << "\n";
	}
	{
		std::cout << CYAN << "float: " << RESET << static_cast<float>(c) << ".0f\n";
	}
	{
		std::cout << GREEN << "double: " << RESET << static_cast<double>(c) << ".0";
	}
}

void ScalarConverter::fromInt(int i)
{
	{
		std::cout << BLUE << "char: " << RESET;
		char c = static_cast<char>(i);
		if (c <= 0 || c >= 127)
			std::cout << IMPOSSIBLE "\n" RESET;
		else if (!isprint(c))
			std::cout << NON_DISPLAYABLE "\n" RESET;
		else
			std::cout << "'" << c << "'\n";
	}
	{
		std::cout << MAGENTA << "int: " << RESET << i << "\n";
	}
	{
		std::cout << CYAN << "float: " << RESET << i << ".0f\n";
	}
	{
		std::cout << GREEN << "double: " << RESET << i << ".0\n";
	}
}

void ScalarConverter::fromFloat(float f, int precision)
{
	int intValue = static_cast<int>(f);
	double reminder = f - intValue;
	{
		std::cout << BLUE << "char: " << RESET;
		char c = static_cast<char>(f);
		if (c <= 0 || c >= 127)
			std::cout << IMPOSSIBLE "\n" RESET;
		else if (!isprint(c))
			std::cout << NON_DISPLAYABLE "\n" RESET;
		else
			std::cout << "'" << c << "'\n";
	}
	{
		std::cout << MAGENTA << "int: " RESET;
		if (std::isnan(f) || std::isinf(f))
			std::cout << RED "impossible" RESET << "\n";
		else
			std::cout << intValue << "\n";
	}
	std::cout << std::fixed << std::setprecision(precision);
	{
		std::cout << CYAN << "float: " << RESET;
		if (reminder == 0.0f)
			std::cout << f << ".0";
		else
			std::cout << f;
		std::cout << "f\n";
	}
	{
		std::cout << GREEN << "double: " << RESET;
		std::cout << std::fixed << std::setprecision(precision);
		if (reminder == 0.0)
			std::cout << f << ".0";
		else
			std::cout << f;
	}
}

void ScalarConverter::fromDouble(double d, int precision)
{
	int intValue = static_cast<int>(d);
	double reminder = d - intValue;
	{
		std::cout << BLUE << "char: " << RESET;
		char c = static_cast<char>(d);
		if (c <= 0 || c >= 127)
			std::cout << IMPOSSIBLE "\n" RESET;
		else if (!isprint(c))
			std::cout << NON_DISPLAYABLE "\n" RESET;
		else
			std::cout << "'" << c << "'\n";
	}
	{
		std::cout << MAGENTA << "int: " RESET;
		if (std::isnan(d) || std::isinf(d))
			std::cout << RED "impossible" RESET << "\n";
		else
			std::cout << intValue << "\n";
	}
	std::cout << std::fixed << std::setprecision(precision);
	{
		std::cout << CYAN << "float: " << RESET;
		if (reminder == 0.0f)
			std::cout << d << ".0";
		else
			std::cout << d;
		std::cout << "f\n";
	}
	{
		std::cout << GREEN << "double: " << RESET;
		std::cout << std::fixed << std::setprecision(precision);
		if (reminder == 0.0)
			std::cout << d << ".0";
		else
			std::cout << d;
	}
}
