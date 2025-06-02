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
                
uintptr_t Serializer::serialize(Data* ptr){return(ptr)}
Data* Serializer::deserialize(uintptr_t raw){return(raw)}

