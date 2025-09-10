#include "PmergeMe.hpp"
#include <sstream>
#include <chrono>

int main (int argc, char **argv){
    try {
    if (argc < 2){
        std::cerr << "No argument given" << std::endl;
        return 0;
    }
    std::vector<int> sort_vector;
    std::deque<int> sort_deque;
    for (int i = 1; i < argc; ++i) 
        {
            std::istringstream iss(argv[i]);
            std::string num;
            int numInt;
            while (iss >> num) 
            {
                if (num.find_first_not_of("0123456789") != std::string::npos)
                    throw std::runtime_error("Error! Invalid characters in input, only digits allowed");
                numInt = stoi(num);
                if (numInt < 0)
                    throw std::runtime_error("Error! negative number in input");
                sort_vector.push_back(numInt);
                sort_deque.push_back(numInt);
            }
        }
    if (is_sorted(sort_vector.begin(), sort_vector.end())){
        std::cerr  << "Already sorted" << std::endl;
        return 0;
    }
    std::cout << "Before:  ";
    for (auto it = sort_vector.begin(); it != sort_vector.end(); ++it){std::cout << *it << " ";}std::cout << "\n";
    PmergeMe Pmerge_vec;
    PmergeMe Pmerge_deq;
    const auto start_vector{std::chrono::steady_clock::now()};
    Pmerge_vec.start(sort_vector,1);
    const auto finish_vector{std::chrono::steady_clock::now()};
    std::chrono::duration<double> elapsed_seconds{finish_vector - start_vector};

    const auto start_deque{std::chrono::steady_clock::now()};
    Pmerge_deq.start(sort_deque,1);
    const auto finish_deque{std::chrono::steady_clock::now()};
    std::chrono::duration<double> elapsed_seconds_deque{finish_deque - start_deque};

    std::cout << "After:   ";
    for (auto it = sort_vector.begin(); it != sort_vector.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "\n";
    std::cout << "Time to process a range of: " << sort_vector.size() << " elements with std::vector: " << std::chrono::duration_cast<std::chrono::microseconds>(elapsed_seconds) << std::endl;
    std::cout << "Time to process a range of: " << sort_deque.size() << " elements with std::deque:  "<<std::chrono::duration_cast<std::chrono::microseconds>(elapsed_seconds_deque) << std::endl;
    } 
    catch (const std::out_of_range& e) 
	{
        std::cout << "Out of range exception: " << e.what() << " !input out of range of integer" << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch (...){
        std::cout << "Error!" << std::endl;
    }
    return 0;
}
