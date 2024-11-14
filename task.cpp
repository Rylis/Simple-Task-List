#include "task.h"
#include <string>
using namespace std;

void Task::setName(string s) {
	this->name = s;
}

void Task::setDate(string s) {
	this->year = stoi(s.substr(0, 4));
	this->month = stoi(s.substr(4, 2));
	this->day = stoi(s.substr(6, 2));
}

void Task::setStatus() {
	this->done = !done;
}

string Task::getName() const {
	return this->name;
}

string Task::getDate() const {
	string dateStr = to_string(this->year) + "/" + to_string(this->month) + "/" + to_string(this->day);
	return dateStr;
}

bool Task::getStatus() const {
	return this->done;
}