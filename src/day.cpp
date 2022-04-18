#include "day.h"
#include "types.h"
#include <iostream>

using namespace std;

namespace day {
	Day::Day(chrono::system_clock::time_point time_point) {
		this->time = chrono::system_clock::to_time_t(time_point);

		struct tm *timeinfo = localtime(&(this->time));

		this->week_day = timeinfo->tm_wday;
		this->year_day = timeinfo->tm_yday;
		this->year_day++; // From zero-based to one-based
	}

	Day::~Day() {}

	void Day::print_date() const {
		cout << "Full date: " << ctime(&(this->time));
	}

	void Day::print_week_day() const {
		string days[MAX_NUM_DAYS] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
		cout << "Day of the week: " << days[this->week_day] << '\n' << endl;
	}

	void Day::print_year_day() const {
		cout << "Day of the year: " << this->year_day << endl;
	}

	void Day::print_trash() const {
		cout << "What is thrown away today:\n";

		switch (this->week_day) {
			case SUNDAY:
				cout << "Organic" << endl;
				break;
			case MONDAY:
				cout << "Nothing" << endl;
				break;
			case TUESDAY:
				cout << "Nothing" << endl;
				break;
			case WEDNESDAY:
				cout << "Organic\n";
				cout << "Dry" << endl;
				break;
			case THURSDAY:
				cout << "It depends..." << endl;
				print_year_day();

				if ((this->year_day + 1) % 14 == 1) cout << "Plastic" << endl;
				else if ((this->year_day + 1) % 14 == 8) cout << "Paper" << endl;
				else cerr << "Error" << endl;

				break;
			case FRIDAY:
				cout << "Nothing" << endl;
				break;
			case SATURDAY:
				cout << "Nothing" << endl;
				break;
			default:
				cerr << "Error" << endl;
				break;
		}
	}
} // namespace day
