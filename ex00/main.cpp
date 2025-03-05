#include <iostream> // input output stream
#include <cctype> // ??

int main(int argc, char **argv) {
	if (argc == 1)
        	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";//character out / statement
	if (argc > 1) {
		for(int j = 1; j < argc; j++) {
			for (int i = 0; argv[j][i] != '\0'; i++)
				std::cout << (char)toupper(argv[j][i]);
		}
		std::cout << "\n";
	}
        return (0);
}
