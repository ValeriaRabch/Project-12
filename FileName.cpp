#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct Student {
	char surname[20], group[5];
	int marks[5];
};

struct Data {
	int day;
	int month;
	int year;
};

struct Man {
	char surname[20], name[10];
	int years;
	Data data;
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

Student* ChangeSizePlus(Student* man, int& size, char surname[], char group[]) {
	size++;
	Student* man2 = new Student[size];
	for (int i = 0; i < size - 1; i++) {
		strcpy(man2[i].surname, man[i].surname);
		strcpy(man2[i].group, man[i].group);
		for (int j = 0; j < 5; j++) {
			man2[i].marks[j] = man[i].marks[j];
		}
	}
	strcpy(man2[size - 1].surname, surname);
	strcpy(man2[size - 1].group, group);
	for (int i = 0; i < 5; i++) {
		man2[size - 1].marks[i] = rand() % 12 + 1;
	}
	delete[]man;
	return man2;
}

Student* ChangeSizeMinus(Student* man, int& size, char surname[], char group[]) {
	size--;
	Student* man2 = new Student[size];
	for (int i = 0; i < size; i++) {
		strcpy(man2[i].surname, man[i].surname);
		strcpy(man2[i].group, man[i].group);
		for (int j = 0; j < 5; j++) {
			man2[i].marks[j] = man[i].marks[j];
		}
	}

	delete[]man;
	return man2;
}

Student* Excellent(Student* man, int size, int& size1) {
	int count = 0; size1 = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 5; j++) {
			if (man[i].marks[j] >= 10) {
				count++;
			}
		}
		if (count >= 3) {
			size1++;
		}
		count = 0;
	}
	if (size1 == 0) {
		return 0;
	}
	Student* excellent = new Student[size1];
	count = 0; int x = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 5; j++) {
			if (man[i].marks[j] >= 10) {
				count++;
			}
		}
		if (count >= 3) {
			strcpy(excellent[x].surname, man[i].surname);
			strcpy(excellent[x].group, man[i].group);
			for (int J = 0; J < 5; J++) {
				excellent[x].marks[J] = man[i].marks[J];
			}
			x++;
		}
		count = 0;
		if (x > size1) {
			break;
		}
	}
	return excellent;
}

Student* Badly(Student* man, int size, int& size1) {
	int count = 0; size1 = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 5; j++) {
			if (man[i].marks[j] < 10) {
				count++;
			}
		}
		if (count >= 3) {
			size1++;
		}
		count = 0;
	}
	if (size1 == 0) {
		return 0;
	}
	Student* badly = new Student[size1];
	count = 0; int x = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < 5; j++) {
			if (man[i].marks[j] < 10) {
				count++;
			}
		}
		if (count >= 3) {
			strcpy(badly[x].surname, man[i].surname);
			strcpy(badly[x].group, man[i].group);
			for (int J = 0; J < 5; J++) {
				badly[x].marks[J] = man[i].marks[J];
			}
			x++;
		}
		count = 0;
		if (x > size1) {
			break;
		}
	}
	return badly;
}

Man* Fulling(Man man[], int size) {
	for (int i = 0; i < size; i++) {
		cout << "Enter surname "; cin >> man[i].surname;
		cout << "Enter name "; cin >> man[i].name;
		cout << "Enter years "; cin >> man[i].years;
		cout << "Enter your birthday date ";
		cin >> man[i].data.day;
		cin >> man[i].data.month;
		cin >> man[i].data.year;
	}
	return man;
}

int main() {
	//завдання 1
	/*int size = 5;
	Student* man = new Student[size];

	for (int i = 0; i < size; i++) {
		cout << "Enter surname "; cin >> man[i].surname;
		cout << "Enter group "; cin >> man[i].group;
		for (int j = 0; j < 5; j++) {
			man[i].marks[j] = rand() % 12 + 1;
		}
	}

	int a = 1; char surname[20], group[5]; int size1 = 5;
	while (a != 6) {
		cout << "Select\n1 - print students\n2 - add student\n3 - delete student\n4 - print excellent  students\n5 - print badly students\n6 - leave"; cin >> a;
		if (a == 1) {
			Print(man, size);
		}
		if (a == 2) {
			cout << "Enter surname "; cin >> surname;
			cout << "Enter group "; cin >> group;
			man = ChangeSizePlus(man, size, surname, group);
		}
		if (a == 3) {
			man = ChangeSizeMinus(man, size, surname, group);
		}
		if (a == 4) {
			size1 = 5;
			Student* excellent = new Student[size1];
			excellent = Excellent(man, size, size1);
			cout << "Excellent list" << endl;
			Print(excellent, size1);
			cout << endl;
			delete[] excellent;
		}
		if (a == 5) {
			size1 = 5;
			Student* badly = new Student[size1];
			badly = Badly(man, size, size1);
			cout << "Badly list" << endl;
			Print(badly, size1);
			delete[] badly;
		}
	}
	delete[] man;*/

	//завдання 2
	int size = 5;
	Man* people = new Man[size];

	char surname[20], name[10]; int years; Data data;
	Fulling(people, size);

	return 0;
}