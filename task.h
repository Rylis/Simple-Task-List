#pragma once
#include <string>
struct Task
{
	private:
		std::string name;
		int year;
		int month;
		int day;
		bool done;

	public:
		void setName(std::string s);
		void setDate(std::string s);
		void setStatus();

		std::string getName() const;
		std::string getDate() const;
		bool getStatus() const;

		Task() {
			setName("new task");
			setDate("20241113");
			done = false;
		};
		Task(std::string name, std::string date) {
			setName(name);
			setDate(date);
			done = false;
		};
};