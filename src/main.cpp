#include "day.h"
#include <iostream>

int main(void) {
	std::cout << "****************\n";
	std::cout << "*   TRASHAPP   *\n";
	std::cout << "****************\n" << std::endl;

	day::Day day(std::chrono::system_clock::now());

	day.print_date();
	day.print_week_day();
	day.print_trash();

	return EXIT_SUCCESS;
}
