#include "day.h"
#include <iostream>

using namespace std;

int main(void) {
	cout << "**********************\n";
	cout << "*      TRASHAPP      *\n";
	cout << "**********************\n" << endl;

	day::Day day(chrono::system_clock::now());

	day.print_date();
	day.print_week_day();
	day.print_trash();

	cout << "End" << endl;
	return EXIT_SUCCESS;
}
