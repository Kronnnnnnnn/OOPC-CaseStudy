#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    float marks;
};

int main() {
    vector<Student> students;
    int choice;

    do {
        cout << "\n--- Student Management System ---\n";
        cout << "1. Add Student\n";
        cout << "2. View All Students\n";
        cout << "3. Search by Student ID\n";
        cout << "4. Exit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(1000, '\n'); 
            cout << "Invalid input! Please enter a number between 1 and 4.\n";
            continue;
        }

        if (choice == 1) {
            Student s;
            cout << "Enter ID: ";
            cin >> s.id;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input! ID must be a number.\n";
                continue;
            }
            cin.ignore(); 
            cout << "Enter Name: ";
            getline(cin, s.name);
            cout << "Enter Marks: ";
            cin >> s.marks;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input! Marks must be a number.\n";
                continue;
            }
            students.push_back(s);
            cout << "Student added successfully.\n";

        } else if (choice == 2) {
            cout << "\n--- View All Students ---\n";
            if (students.empty()) {
                cout << "No students have been added yet.\n";
            } else {
                cout << "List of all stored student details:\n";
                for (int i = 0; i < students.size(); i++) {
                    cout << "ID: " << students[i].id
                         << ", Name: " << students[i].name
                         << ", Marks: " << students[i].marks << "\n";
                }
            }

        } else if (choice == 3) {
            cout << "\n--- Search Student by ID ---\n";
            if (students.empty()) {
                cout << "No student records available to search.\n";
                continue;
            }
            int id;
            cout << "Enter ID to search: ";
            cin >> id;
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input! ID must be a number.\n";
                continue;
            }

            bool found = false;
            for (int i = 0; i < students.size(); i++) {
                if (students[i].id == id) {
                    cout << "Student found:\n";
                    cout << "ID: " << students[i].id
                         << ", Name: " << students[i].name
                         << ", Marks: " << students[i].marks << "\n";
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Student with ID " << id << " not found.\n";
            }

        } else if (choice == 4) {
            cout << "Exiting the program. Thank you for using the Student Management System!\n";

        } else {
            cout << "Invalid option! Please choose a number between 1 and 4.\n";
        }

    } while (choice != 4);

    return 0;
}