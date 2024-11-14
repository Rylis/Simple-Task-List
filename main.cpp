#include <iostream>
#include <vector>

#include "task.h"
#include "function.h"

using namespace std;

int main()
{
	vector<Task> vec;
	int choice;
	bool menu = true;
	while (menu != false) {
		cout << "*******************************\n";
		cout << "Current Tasks: " << vec.size() << "\n";
		cout << "*******************************\n";
		cout << " 0 - View Tasks\n";
		cout << " 1 - Add a Task\n";
		cout << " 2 - Update task status\n";
		cout << " 3 - Delete a Task\n";
		cout << " 4 - Exit\n\n";
		cout << " Enter your choice and press enter: ";

		cin >> choice;

		switch (choice)
		{
			case 0:
				printTasks(vec);
				break;
			case 1:
				if (createTask(vec)) {
					cout << "\nTask successfully created.\n\n";
				}
				else {
					cout << "\nTask not created.\n\n";
				}
				break;
			case 2:
				updateStatus(vec);
				break;
			case 3:
				deleteTask(vec);
				break;
			case 4:
				cout << "End of Program.\n";
				menu = false;
				break;
			default:
				cout << "Not a Valid Choice. \n";
				cout << "Choose again.\n";
				break;
		}

		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
	return 0;
}