#ifndef POLISH_HPP
#define POLISH_HPP

#include <string>
#include <iostream>
#include <iterator>
#include <stack>
#include <sstream>
#include <cctype>
#include <cstdlib>

class Polish {
    private:
        std::stack<int> _stack;
    public:
        Polish();
        Polish(const std::string &argv);
        ~Polish();
        Polish(const Polish &copy);
        Polish& operator=(const Polish &rhs); 

        ///void calculate_rpn();
        void calculate_instance(int n1, int n2, char op);

};

#endif