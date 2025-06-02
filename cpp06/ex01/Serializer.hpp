#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <iostream>

typedef struct Data {
	str::string Name;
	int number;
	str::string type;
} Data;

class Serializer {
	private:
		Serializer();
                Serializer(const Serializer &copy);
                Serializer& operator=(const Serializer &rhs);
                ~Serializer();
	public:
		uintptr_t serialize(Data* ptr);
		Data* deserialize(uintptr_t raw);
};

#endif
