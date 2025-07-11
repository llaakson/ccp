#include "Serializer.hpp"

Serializer::Serializer(){}

Serializer::Serializer(const Serializer &copy){
	*this = copy;
}
Serializer& Serializer::operator=(const Serializer &rhs){
	if (this != &rhs)
		*this = rhs;
	return *this;
}

Serializer::~Serializer(){}
                
uintptr_t Serializer::serialize(Data* ptr){return reinterpret_cast<std::uintptr_t>(ptr);}
Data* Serializer::deserialize(uintptr_t raw){return reinterpret_cast<Data *>(raw);}

