#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

vector<Task> taskList;

// Function to add a task to the list
void addTask() {
    Task newTask;
    cout << "Enter task description: ";
    getline(cin, newTask.description);
    newTask.completed = false;
    taskList.push_back(newTask);
    cout << "Task added successfully!" << endl;
}

// Function to view tasks
void viewTasks() {
    cout << "Task List:" << endl;
    for (int i = 0; i < taskList.size(); i++) {
        cout << "[" << (i + 1) << "] " << taskList[i].description;
        if (taskList[i].completed) {
            cout << " (Completed)";
        }
        cout << endl;
    }
}

// Function to mark a task as completed
void markTaskAsCompleted() {
    int taskNumber;
    cout << "Enter the task number to mark as completed: ";
    cin >> taskNumber;
    if (taskNumber > 0 && taskNumber <= taskList.size()) {
        taskList[taskNumber - 1].completed = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

// Function to remove a task
void removeTask() {
    int taskNumber;
    cout << "Enter the task number to remove: ";
    cin >> taskNumber;
    if (taskNumber > 0 && taskNumber <= taskList.size()) {
        taskList.erase(taskList.begin() + taskNumber - 1);
        cout << "Task removed successfully!" << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

int main() {
    int choice;
    while (true) {
        cout << "To-Do List Manager" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                markTaskAsCompleted();
                break;
            case 4:
                removeTask();
                break;
            case 5:
                return 0;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }

    return 0;
}