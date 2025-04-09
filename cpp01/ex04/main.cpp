#include <iostream>
#include <fstream>
#include <string>

int main(int argc, char **argv){
	if (argc != 4){
		std::cerr << "Error! Incorrect argument count" << std::endl;
		return 1;
	}
	std::string haystack = argv[1];
	std::ifstream file;
	file.open (haystack);
	if (!file.is_open()) {
            std::cerr << "Failed to open file: " << argv[1] << std::endl;
            return 1;
        }
	std::string line;
	std::string needle = argv[2];
    std::string newneedle = argv[3];
	char c;
	while (file.peek() != EOF && file >> std::noskipws >> c)
		line += c;
	size_t found = 0;
	while ((found = line.find(needle)) != std::string::npos) {
		line.erase(found, needle.length());
		line.insert(found, newneedle);
		found += newneedle.length();
	}
	std::ofstream outfile;
	outfile.open(haystack + ".replace");
	if (!outfile.is_open()) {
            std::cerr << "Failed to create outfile" << std::endl; 
	    file.close();
            return 1;    
        }
	outfile << line;
	outfile.close();	
	file.close();
	return 0;
}
