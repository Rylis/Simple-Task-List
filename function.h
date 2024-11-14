#pragma once
#include <string>
#include <vector>
#include "task.h"

void printTasks(std::vector<Task> vec);
bool createTask(std::vector<Task>& vec);
void updateStatus(std::vector<Task>& vec);
void deleteTask(std::vector<Task>& vec);

bool verifyDate(std::string s);