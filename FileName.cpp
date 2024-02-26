#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct Student {
	char surname[20], group[5];
	int marks[5];
};

void Print(Student* man, int size) {
	for (int i = 0; i < size; i++) {

		cout << "Surname -" << man[i].surname << endl;
		cout << "Group -" << man[i].group << endl;
		for (int j = 0; j < 5; j++) {
			cout << "Marks -";
			cout << man[i].marks[j] << endl;
		}
	}
}

int main() {
	//завдання 1
	int size = 5;
	Student* man = new Student[size];

	for (int i = 0; i < size; i++) {
		cout << "Enter surname "; cin >> man[i].surname;
		cout << "Enter group "; cin >> man[i].group;
		for (int j = 0; j < 5; j++) {
			man[i].marks[j] = rand() % 12 + 1;
		}
	}

	int a = 1;
	while (a != 6) {
		cout << "Select\n1 - print students\n2 - add student\n3 - delete student\n4 - print excellent  students\n5 - print badly students\n6 - leave"; cin >> a;
		if (a == 1) {
			Print(man, size);
		}
	}

	return 0;
}