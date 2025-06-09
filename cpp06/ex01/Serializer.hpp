#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP
#include <iostream>
#include <cstdint>
#include <stdint.h>
#include "Data.hpp"

class Serializer {
	private:
		Serializer() = delete;
        Serializer(const Serializer &copy) = delete;
        Serializer& operator=(const Serializer &rhs) = delete;
        ~Serializer() = delete;
	public:
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif
