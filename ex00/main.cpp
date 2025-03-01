#include <iostream> // input output stream
#include <cctype> // ??

int main(int argc, char **argv) {
	int i = 0;
	if (argc == 1)
        	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";//character out / statement
	if (argc > 1) {
		while (argv[1][i] != '\0') {
			std::cout << (char)toupper(argv[1][i]);
			i++;
		}
		std::cout << "\n";
	}
        return (0);
}
