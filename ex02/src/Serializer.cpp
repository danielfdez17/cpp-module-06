#include "Base.hpp"
#include "utils.hpp"

Base::~Base()
{
	std::cout << RED << __func__ << " destructor called\n" RESET;
}
