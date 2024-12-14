#include <iostream>

#include <ansi.hpp>



int main()
{
	std::cout << saveCursorPosition();

	for (size_t i = 0; i < 99999999; i++)
		std::cout << i << loadCursorPosition();

	return 0;
}
