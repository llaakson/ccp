#ifndef POLISH_HPP
#define POLISH_HPP

#include <string>
#include <deque>
#include <iostream>
#include <iterator>

class Polish {
    private:
        std::deque<int> _stack;
    public:
        Polish();
        Polish(char *argv);
        ~Polish();
        Polish(const Polish &copy);
        Polish& operator=(const Polish &rhs); 

        void calculate_rpn();
        int calculate_instance(int n1, int n2, char op);

};

#endif