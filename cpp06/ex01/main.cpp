#include "Serializer.hpp"
#include "Data.hpp"

int main()
{
	try {
	Data *pika = new Data();
	pika->open_datadex();
	std::cout << "Data* is " << pika << std::endl;
	std::cout << "Starting operation serialization" << std::endl;
	uintptr_t pika_t = Serializer::serialize(pika);

	std::cout << "Serialization completed! uintptr_t is: " << pika_t << std::endl;

	std::cout << "Starting operation deserialization" << std::endl;
	Data *pika_new = Serializer::deserialize(pika_t);

	std::cout << "Serialization completed! Data* is " << pika_new << std::endl;
	pika_new->open_datadex();
	delete pika;
	}
	catch (const std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	/*try {
	Data *pika = new Data();
	Data *pika2 = new Data();
	//pika->open_datadex();
	std::cout << "ptr* of pika  is " << pika << std::endl;
	std::cout << "ptr* of pika2 is " << pika2 << std::endl;
	std::cout << "Starting operation serialization" << std::endl;
	uintptr_t pika_t = Serializer::serialize(pika);
	uintptr_t pika_t2 = Serializer::serialize(pika2);

	std::cout << "Serialization completed! pika_t is:  " << pika_t << std::endl;
	std::cout << "Serialization completed! pika_t2 is: " << pika_t2 << std::endl;

	pika_t ^= pika_t2;
	pika_t2 ^= pika_t;
	pika_t ^= pika_t2;

	std::cout << "Starting operation deserialization" << std::endl;
	Data *pika_new = Serializer::deserialize(pika_t);
	Data *pika_new2 = Serializer::deserialize(pika_t2);

	std::cout << "ptr* of pika  is " << pika_new << std::endl;
	std::cout << "ptr* of pika2 is " << pika_new2 << std::endl;
	pika_new->open_datadex();
	delete pika2;
	delete pika;
	}
	catch (const std::exception& e){
		std::cerr << e.what() << std::endl;
	}
	return 0;*/
}