#include "day.h"
#include "types.h"
#include <iostream>

namespace day {
	Day::Day(std::chrono::system_clock::time_point time_point) {
		this->time = std::chrono::system_clock::to_time_t(time_point);

		struct tm *timeinfo = std::localtime(&(this->time));

		this->week_day = timeinfo->tm_wday;
		this->year_day = timeinfo->tm_yday;
		this->year_day++; // From zero-based to one-based
	}

	Day::~Day() {}

	void Day::print_date() const {
		std::cout << "Full date: " << std::ctime(&(this->time));
	}

	void Day::print_week_day() const {
		std::cout << "Day of the week starting from Sunday: " << this->week_day << "\n";

		std::string days[max_num_days] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
		std::cout << "Day of the week: " << days[this->week_day] << std::endl;
	}

	void Day::print_year_day() const {
		std::cout << "Day of the year: " << this->year_day << std::endl;
	}

	void Day::print_trash() const {
		std::cout << "What is thrown away today:\n";

		switch (this->week_day) {
			case sunday:
				std::cout << "Organic" << std::endl;
				break;
			case monday:
				std::cout << "Nothing" << std::endl;
				break;
			case tuesday:
				std::cout << "Nothing" << std::endl;
				break;
			case wednesday:
				std::cout << "Organic\n";
				std::cout << "Dry" << std::endl;
				break;
			case thursday:
				std::cout << "It depends..." << std::endl;
				print_year_day();

				if ((this->year_day + 1) % 14 == 1) std::cout << "Plastic" << std::endl;
				else if ((this->year_day + 1) % 14 == 8) std::cout << "Paper" << std::endl;
				else std::cerr << "Error" << std::endl;

				break;
			case friday:
				std::cout << "Nothing" << std::endl;
				break;
			case saturday:
				std::cout << "Nothing" << std::endl;
				break;
			default:
				std::cerr << "Error" << std::endl;
				break;
		}
	}
} // namespace day
