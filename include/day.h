#ifndef DAY_H
#define DAY_H

#include <chrono>

namespace day {
	class Day {
	private:
		time_t time;
		int week_day;
		int year_day;
	public:
		Day(std::chrono::system_clock::time_point time_point);
		virtual ~Day();
		void print_date() const; // Prints the complete date
		void print_week_day() const; // Prints the day of the week
		void print_year_day() const; // Prints the day of the year
		void print_trash() const;  // Prints the waste to throw away
	};
} // namespace day

#endif // DAY_H
