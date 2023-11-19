#include <iostream>
#include <string>
#include <limits>

using namespace std;

const int MAX_STUDENTS = 50;

// Arrays utk simpan data
int studentID[MAX_STUDENTS];
string studentName[MAX_STUDENTS];
double scores[MAX_STUDENTS];
int attendance[MAX_STUDENTS];


int readInt(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number." << endl;
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

// Function utk input data student
void inputStudentData(int &numStudents) {
    numStudents = readInt("Enter number of students (max 50): ");
    numStudents = min(numStudents, MAX_STUDENTS); // Ensure not exceeding max limit

    for (int i = 0; i < numStudents; ++i) {
        cout << "Enter data for student " << (i + 1) << endl;
        studentID[i] = readInt("Student ID: ");
        cout << "Student Name: ";
        getline(cin, studentName[i]);
        scores[i] = readInt("Score: ");
        attendance[i] = readInt("Attendance (%): ");
    }
}

// Function utk kira makrah avrg 
double calculateAverageScores(int numStudents) {
    if (numStudents == 0) return 0.0; // Prevent division by zero

    double total = 0.0;
    for (int i = 0; i < numStudents; ++i) {
        total += scores[i];
    }
    return total / numStudents;
}

// Function utk display student records
void displayStudentRecords(int numStudents, double averageScore) {
    cout << "\nStudent Records:\n";
    cout << "ID\tName\tScore\tAttendance\n";
    for (int i = 0; i < numStudents; ++i) {
        cout << studentID[i] << "\t" << studentName[i] << "\t"
             << scores[i] << "\t" << attendance[i] << "%\n";
    }
    cout << "Average Score of Students: " << averageScore << endl;
}

int main() {
    int numStudents = 0;
    inputStudentData(numStudents);
    double averageScore = calculateAverageScores(numStudents);
    displayStudentRecords(numStudents, averageScore);
    return 0;
}
