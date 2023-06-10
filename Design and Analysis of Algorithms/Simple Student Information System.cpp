#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Define a struct to represent a student
struct Student {
    string name;
    int id;
    string course;
};

// Define a vector to hold the students
vector<Student> students;

// Function to add a new student
void addStudent() {
    Student s;
    cout << "Enter student name: " << endl;
    getline(cin, s.name);
    cout << "You entered: " << s.name << endl;

    cout << "Enter student ID: " << endl;
    cin >> s.id;
    cout << "You entered: " << s.id << endl;

    cin.ignore(); // to clear the input buffer

    cout << "Enter student course: " << endl;
    getline(cin, s.course);
    cout << "You entered: " << s.course << endl;

    students.push_back(s);
    cout << "Student added successfully!\n";
}

// Function to delete a student
void deleteStudent() {
    int id;
    cout << "Enter ID of student to delete: ";
    cin >> id;
    bool found = false;
    for (int i = 0; i < students.size(); i++) {
        if (students[i].id == id) {
            students.erase(students.begin() + i);
            found = true;
            cout << "Student deleted successfully!\n";
            break;
        }
    }
    if (!found) {
        cout << "Student not found.\n";
    }
}

// Function to edit a student
void editStudent() {
    int id;
    cout << "Enter ID of student to edit: ";
    cin >> id;
    bool found = false;
    for (int i = 0; i < students.size(); i++) {
        if (students[i].id == id) {
            cout << "Enter new name (or press enter to keep current name): ";
            string name;
            getline(cin, name);
            if (!name.empty()) {
                students[i].name = name;
            }
            cout << "Enter new course (or press enter to keep current course): ";
            string course;
            getline(cin, course);
            if (!course.empty()) {
                students[i].course = course;
            }
            found = true;
            cout << "Student edited successfully!\n";
            break;
        }
    }
    if (!found) {
        cout << "Student not found.\n";
    }
}

// Function to list all students
void listStudents() {
    if (students.empty()) {
        cout << "No students to display.\n";
    } else {
        cout << "ID\tName\tCourse\n";
        for (int i = 0; i < students.size(); i++) {
            cout << students[i].id << "\t" << students[i].name << "\t" << students[i].course << endl;
        }
    }
}

// Function to search for a student by name
void searchByName() {
    string name;
    cout << "Enter name to search for: ";
    getline(cin, name);
    bool found = false;
    cout << "ID\tName\tCourse\n";
    for (int i = 0; i < students.size(); i++) {
        if (students[i].name == name) {
            cout << students[i].id << "\t" << students[i].name << "\t" << students[i].course << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No students found with that name.\n";
    }
}

// Function to search students by ID
void searchById() {
    int id;
    cout << "Enter ID to search for: ";
    cin >> id;
    bool found = false;
    for (const auto& s : students) {
        if (s.id == id) {
            cout << "Name: " << s.name << "\n";
            cout << "ID: " << s.id << "\n";
            cout << "Course: " << s.course << "\n\n";
            found = true;
        }
    }
    if (!found) {
        cout << "No student with the ID " << id << " was found.\n";
    }
}

// Function to search students by course
void searchByCourse() {
    string course;
    cout << "Enter course to search for: ";
    getline(cin, course);
    bool found = false;
    for (const auto& s : students) {
        if (s.course == course) {
            cout << "Name: " << s.name << "\n";
            cout << "ID: " << s.id << "\n";
            cout << "Course: " << s.course << "\n\n";
            found = true;
        }
    }
    if (!found) {
        cout << "No student enrolled in the course " << course << " was found.\n";
    }
}




int main() {
    int choice;
    while (true) {
        cout << "          Select an option:\n";
        cout << "                                   \n";
        cout << "///////////////////////////////////\n";
        cout << "/// 1. Add student              ///\n";
        cout << "///////////////////////////////////\n";
        cout << "                                   \n";
        cout << "///////////////////////////////////\n";
        cout << "/// 2. Edit student             ///\n";
        cout << "///////////////////////////////////\n";
        cout << "                                   \n";
        cout << "///////////////////////////////////\n";
        cout << "/// 3. Delete student           ///\n";
        cout << "///////////////////////////////////\n";
        cout << "                                   \n";
        cout << "///////////////////////////////////\n";
        cout << "/// 4. List of students         ///\n";
        cout << "///////////////////////////////////\n";
        cout << "                                   \n";
        cout << "///////////////////////////////////\n";
        cout << "/// 5. Search student by name   ///\n";
        cout << "///////////////////////////////////\n";
        cout << "                                   \n";
        cout << "///////////////////////////////////\n";
        cout << "/// 6. Search student by id     ///\n";
        cout << "///////////////////////////////////\n";
        cout << "                                   \n";
        cout << "///////////////////////////////////\n";
        cout << "/// 7. Search student by course ///\n";
        cout << "///////////////////////////////////\n";
        cout << "                                   \n";
        cout << "///////////////////////////////////\n";
        cout << "/// 8. Exit                     ///\n";
        cout << "///////////////////////////////////\n";
        cout << "                                   \n";
        cout << "                                   \n";

        cin >> choice;
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                editStudent();
                break;
            case 3:
                deleteStudent();
                break;
            case 4:
               listStudents();
                break;
            case 5:
               searchByName();
                break;
            case 6:
               searchById();
                break;
            case 7:
               searchByCourse();
                break;
            case 8:
                cout << "Exiting....\n";
            default:
                cout << "Invalid choice. Please try again.\n";
                cout << "                                 \n";
                cout << "                                 \n";

        }
    }
     return 0;
}





