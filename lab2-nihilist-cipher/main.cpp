#include <iostream>
#include <string>
#include "cipher.h"
#include <time.h>

int main()
{
	srand(time(NULL));
	PolybiusSquare square;
	std::cin >> square;
	std::cin.ignore();
	std::cout << square << std::endl;
	std::string encrypted = encrypt(square, "kot", "dwa psy jjj ./.,");
	std::cout << encrypted << std::endl;
	std::string decrypted = decrypt(square, "kot", encrypted);
	std::cout << decrypted << std::endl;
	return 0;
}