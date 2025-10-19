#include <iostream>

using namespace std;

struct Student {
	string name;
	int grade;
};

void enterStudents(Student *students, int length) {
	cout << "Enter names and grades of students" << endl;
	for (int i = 0; i < length; i++) {
		string nameOfStudent;
		cin >> nameOfStudent;
		int studentGrade;
		cin >> studentGrade;
		students[i].name = nameOfStudent;
		students[i].grade = studentGrade;
	}
}

void sortStudents(Student* students, int length) {
	for (int i = 0; i < length; i++) {
		int largestIndex = i;
		for (int j = i + 1; j < length; j++) {
			if (students[j].grade > students[largestIndex].grade)
				largestIndex = j;
		}
		swap(students[i], students[largestIndex]);
	}
}

void printStudents(Student* students, int length) {
	for (int i = 0; i < length; i++) {
		cout << students[i].name << " got a grade of " << students[i].grade << endl;
	}
}

int main() {
	cout << "Enter the number of students: ";
	int numStudents;
	cin >> numStudents;
	Student* students = new Student[numStudents];
	enterStudents(students, numStudents);
	sortStudents(students, numStudents);
	printStudents(students, numStudents);
}