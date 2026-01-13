#pragma once
#ifndef __SCALARCONVERTER__
#define __SCALARCONVERTER__

#include <string>
#include <iostream>

class ScalarConverter {
private:

	static void	toChar(std::string s);
	static void	toInt(std::string s);
	static void	toFloat(std::string s);
	static void	toDouble(std::string s);

public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& copy);
	ScalarConverter& operator=(const ScalarConverter& copy);
	~ScalarConverter();
	
	static void convert(std::string s);
	
};

#endif // __SCALARCONVERTER__