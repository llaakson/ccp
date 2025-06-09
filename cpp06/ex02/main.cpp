#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <stdlib.h>
#include <ctime>
#include <iostream>

Base * generate(void){
	
	if (rand()%100 % 3 == 0)
		return new A;
	else if (rand()%100 % 3 == 1)
		return new B;
	else
		return new C;
}

void identify(Base* p){
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;

}
//https://stackoverflow.com/questions/1276847/difference-in-behavior-while-using-dynamic-cast-with-reference-and-pointers
void identify(Base& p){
	try {
		A &a = dynamic_cast<A&>(p);
		(void)a;
			//if (a != NULL)
				std::cout << "A" << std::endl;}
	catch (std::bad_cast exp){
		//std::cout << "BAD cast a" << std::endl;
	}
	try {B &b = dynamic_cast<B&>(p);
		(void)b;
		//if (b != NULL)
			std::cout << "B" << std::endl;}
		catch (std::bad_cast exp){
			//std::cout << "BAD cast b" << std::endl;
		}
	try {C &c = dynamic_cast<C&>(p);
		(void)c;
			//if (c != NULL)
				std::cout << "C" << std::endl;}
			catch (std::bad_cast exp){
				//std::cout << "BAD cast c" << std::endl;
			}
}

int main()
{
	srand(time(NULL));
	for (int i = 0; i < 20; i++)
	{
		Base *base1 = generate();
		identify(base1);
		identify(*base1);
	}
	return 0;
}