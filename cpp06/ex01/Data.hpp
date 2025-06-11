#ifndef DATA_HPP
#define DATA_HPP
#include <iostream>

class Data {
        private:
                std::string _name;
	        int _number;
	        std::string _type;
        public:
		Data();
                Data(const Data &copy);
                Data& operator=(const Data &rhs);
                ~Data();
                void open_datadex();
};

#endif
