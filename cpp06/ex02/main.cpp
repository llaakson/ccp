#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <stdlib.h>
#include <ctime>
#include <iostream>

Base * generate(void){
	int random = rand()%100 % 3;
	if (random == 0)
		return new A;
	else if (random == 1)
		return new B;
	else
		return new C;
}

void identify(Base* p){
	if (dynamic_cast<A*>(p) != nullptr)
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p) != nullptr)
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p) != nullptr)
		std::cout << "C" << std::endl;
	else
		std::cout << "Failed to cast pointer" << std::endl;
	
}
void identify(Base& p){
	try {
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return ;}
	catch (std::bad_cast exp){
	}
	try {B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return ;}
		catch (std::bad_cast exp){
		}
	try {C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
		return ;}
			catch (std::bad_cast exp){
	}
	std::cout << "Failed to cast reference" << std::endl;
}

int main()
{
	srand(time(NULL));
	try {
	for (int i = 0; i < 10; i++)
	{
		Base *base1 = generate();
		identify(base1);
		delete base1;
	}
	}
	catch (...){
		std::cerr << "Unexpected error" << std::endl;
	}
	try {
	for (int i = 0; i < 10; i++)
	{
		Base *base1 = generate();
		identify(*base1);
		delete base1;
	}
	}
	catch (...){
		std::cerr << "Unexpected error" << std::endl;
	}
	try{
		Base *base2 = nullptr;
		identify(base2);
		identify(*base2);
	} catch (...) {
		std::cerr << "Unexpected error" << std::endl;
	}
	return 0;
}