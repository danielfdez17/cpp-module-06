#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "utils.hpp"
#include <cstdlib>
#include <exception>

static Base	*generate(void)
{
	int r = rand();
	switch (r % 3)
	{
	case 0:
		return new A();
	case 1:
		return new B();
	default:
		return new C();
	}
}

static void identify(Base *p)
{
	// ? prints the actual type of the object pointed to by p
	A *a = dynamic_cast<A*>(p);
	if (a)
	{
		std::cout << YELLOW "Trying to convert 'Base *' to 'A *'...: "
		<< GREEN "p is an instance of A\n" RESET;
		return;
	}
	B *b = dynamic_cast<B*>(p);
	if (b)
	{
		std::cout << YELLOW "Trying to convert 'Base *' to 'B *'...: "
		<< BLUE "p is an instance of B\n" RESET;
		return;
	}
	C *c = dynamic_cast<C*>(p);
	if (c)
	{
		std::cout << YELLOW "Trying to convert 'Base *' to 'C *'...: "
		<< MAGENTA "p is an instance of C\n" RESET;
		return;
	}
	std::cout << RED "p is an instance of undefined\n" RESET;
}

static void identify(Base &p)
{
	// ? prints the actual type of the object referenced by p
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << YELLOW "Trying to convert 'Base &' to 'A &'...: "
		<< GREEN "p is an instance of A\n" RESET;
		return;
	} catch (std::exception &bc)
	{
		std::cerr << RED "Conversion to A is not valid: " << bc.what() << "\n" RESET;
	}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << YELLOW "Trying to convert 'Base &' to 'B &'...: "
		<< BLUE "p is an instance of B\n" RESET;
		return;
	} catch (std::exception &bc)
	{
		std::cerr << RED "Conversion to B is not valid: " << bc.what() << "\n" RESET;
	}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << YELLOW "Trying to convert 'Base &' to 'C &'...: "
		<< MAGENTA "p is an instance of C\n" RESET;
		return;
	} catch (std::exception &bc)
	{
		std::cerr << RED "Conversion to C is not valid: " << bc.what() << "\n" RESET;
	}
	std::cout << RED "p is an instance of undefined\n" RESET;
}

int main(void)
{
	std::srand(std::rand());
	Base *b1 = generate();
	Base *b2 = generate();
	Base *b3 = generate();
	identify(b1);
	identify(b2);
	identify(b3);
	identify(*b1);
	identify(*b2);
	identify(*b3);
	delete b1;
	delete b2;
	delete b3;
	return 0;
}