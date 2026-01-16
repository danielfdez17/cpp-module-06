#pragma once
#ifndef __SCALARCONVERTER_HPP__
#define __SCALARCONVERTER_HPP__

#include <string>
#include <iostream>

class ScalarConverter {
private:

	static void	toChar(double value);
	static void	toInt(double value);
	static void	toFloat(double value);
	static void	toDouble(double value);
	
public:

	ScalarConverter();
	ScalarConverter(const ScalarConverter& copy);
	ScalarConverter& operator=(const ScalarConverter& copy);
	~ScalarConverter();
	
	static void convert(std::string s);
	
};

#endif // __SCALARCONVERTER_HPP__