#include "Polish.hpp"

Polish::Polish(){}

Polish::~Polish(){}

Polish::Polish(const Polish &copy){ 
    *this = copy;
}

Polish& Polish::operator=(const Polish &rhs){
    if (this != &rhs)
        return *this;
    return *this;
}

int Polish::calculate_instance(int n1, int n2, char op){
if (op == '+')
    return n1 + n2;
else if (op == '-')
    return n1 - n2;
else if (op == '*')
    return n1 * n2;
else{
    if (n2 == 0){
        std::cerr << "Error! Division by zero" << std::endl;
        throw 420;}
    return n1 / n2;
    } // check diviosion with 0??
}

void Polish::calculate_rpn(){
int temp = 0;
while(!_stack.empty())
{ 
    int n1 = _stack[0];
    int n2 = _stack[1];
    char current_operator = _stack[2] + '0';
   //std::cout << n1 << current_operator << n2 << std::endl;
    temp = calculate_instance(n1,n2,current_operator);
    _stack.pop_front();
    _stack.pop_front();
    _stack.pop_front();
    if (_stack.empty()){
        std::cout << temp << std::endl;
        break ;
    }
    _stack.push_front(temp);
}
}

Polish::Polish(char *argv)
{
int size = static_cast<std::string>(argv).size();
if (size < 5){
    std::cerr << "Error! Not a valid operation" << std::endl;
    throw 420;}
if (static_cast<std::string>(argv).find_first_not_of("+/-*0123456789 ") != std::string::npos){
    std::cerr << "Error! Invalid characters use only: '+/-*0123456789 '" << std::endl;
    throw 420;}
int i = 0;
while (argv[i])
{
    if (argv[i] == ' '){
        i++;
        continue;
    }
    _stack.push_back(argv[i] - '0');
    i++;
    if (!(argv[i] == ' ') && i != size){
         std::cerr << "Error! Separate numbers/operators with space" << std::endl;
         throw 420;}
}

// NEED TO REWRITE THIS MESSS !!!

unsigned int j = 1;
if (!(_stack[0] + '0' >= '0' &&  _stack[0] <= '9' + '0' )){
        std::cerr << "Error! Not valid order of numbers/operators" << std::endl;
        throw 420;}
while(_stack.size() > j)
{
    if ((_stack[j] + '0' >= '0' &&  _stack[j] <= '9' + '0' ) && (j % 2 == 0)){
        std::cerr << "Error! Not valid order of numbers/operators" << std::endl;
        throw 420;}
    else if ((_stack[j] == '+' + '0' ||  _stack[j] == '-' + '0' || _stack[j] == '*' + '0' ||  _stack[j] == '/' + '0') && (j % 2 != 0)){
        std::cerr << "Error! Not valid order of numbers/operators" << std::endl;
        throw 420;}
    //std::cout << "Stack j is: " << _stack[j] + '0' << std::endl;
    j++;
}
}

// std::deque<int>::iterator it;
// for (it = _stack.begin(); it != _stack.end(); ++it)
//     std::cout << *it << "\n";