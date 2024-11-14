#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include "function.h"
#include "task.h"
using namespace std;

void printTasks(vector<Task>& vec) {
	displayTasks(vec);

	cout << "\nPress Enter to Continue...\n";
	cin.ignore();
}

bool createTask(vector<Task>& vec) {
	string name, date;

	cout << "Create new task name:";
	cin >> name;
	cout << "\n";
	cout << "Set new task date (YYYYMMDD):";
	cin >> date;

	//check if valid date
	if (!verifyDate(date)) {
		cout << "Invalid date entered.";
		return false;
	}

	Task t(name, date);

	vec.push_back(t);
	return true;
}

void updateStatus(vector<Task>& vec) {
	cout << "\n";
	//if there are no tasks
	if (vec.empty()) {
		cout << "There are no tasks.";
		return;
	}

	int i;
	cout << "Input task no. to change status: ";
	cin >> i;
	cin.ignore();

	//if not within range of vec
	if (!(i >= 0 && i < vec.size())) {
		cout << "Invalid no. entered.\n";
		return;
	}

	if (vec.at(i).getStatus()) {
		cout << "Task set to \'Pending\'\n";
	}
	else {
		cout << "Task set to \'Completed\'\n";
	}
	cout << "\nPress Enter to Continue...\n";
	vec.at(i).setStatus();
}

void deleteTask(vector<Task>& vec) {
	//if there are no tasks
	if (vec.empty()) {
		cout << "There are no tasks.\n\n";
		return;
	}

	int i;
	cout << "Input task no. to delete: \n";
	cin >> i;
	cin.ignore();

	//if not within range of vec
	if (!(i >= 0 && i < vec.size())) {
		cout << "Invalid no. entered.\n";
		return;
	}

	vec.erase(vec.begin() + i);
	cout << "Task deleted.\n";
}

void sortTasks(vector<Task>& vec) {
	//if there are no tasks
	if (vec.empty()) {
		cout << "There are no tasks.\n\n";
		return;
	}
	if (vec.size() != 1) {
		sort(vec.begin(), vec.end(), compareDate);
	}
	displayTasks(vec);
}

void displayTasks(vector<Task>& vec) {
	cout << "*******************************\n";
	cout << "No.\t" << "DATE\t\t" << "Status\t\t" << "NAME" << "\n";

	for (int i = 0; i < vec.size();i++) {
		cout << i << "\t" << vec.at(i).getDate() << "\t";
		if (vec.at(i).getStatus()) {
			cout << "Completed";
		}
		else {
			cout << "Pending\t";
		}
		cout << "\t" << vec.at(i).getName() << "\n";
	}
}

bool verifyDate(string s) {
	if (s.length() != 8) return false;
	string::const_iterator it = s.begin();
	while (it != s.end() && isdigit(*it)) it++;
	return !s.empty() && it == s.end();
}

bool compareDate(Task t1, Task t2) {
	return (t1.getDate() < t2.getDate());
}
