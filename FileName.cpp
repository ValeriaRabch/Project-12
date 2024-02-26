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

Man* SortingName(Man man[], int size) {
	Man q;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (strcmp(man[j].name, man[j + 1].name) == 1) {
				q = man[j];
				man[j] = man[j + 1];
				man[j + 1] = q;
			}
		}
	}
	return man;
}

Man* SortingSurname(Man man[], int size) {
	Man q;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (strcmp(man[j].surname, man[j + 1].surname) == 1) {
				q = man[j];
				man[j] = man[j + 1];
				man[j + 1] = q;
			}
		}
	}
	return man;
}

void PrintMan(Man man[], int size) {
	for (int i = 0; i < size; i++) {
		cout << "Surname -" << man[i].surname << endl;
		cout << "Name -" << man[i].name << endl;
		cout << "Years -" << man[i].years << endl;
		cout << "Data birthday -" << man[i].data.day << '.' << man[i].data.month << '.' << man[i].data.year << endl;
	}
}

Man* listShenninniks(Man man[], int size, int month, int& size1) {
	size1 = 0;
	for (int i = 0; i < size; i++) {
		if (man[i].data.month == month) {
			size1++;
		}
	}
	Man* people = new Man[size1];
	int index = 0;
	for (int i = 0; i < size; i++) {
		if (man[i].data.month == month) {
			strcpy(people[index].surname, man[i].surname);
			strcpy(people[index].name, man[i].name);
			people[index].years = man[i].years;
			people[index].data = man[i].data;
			index++;
		}
	}
	return people;
}

Man* AddMan(Man man[], int& size, char surname[], char name[], int years, Data data) {
	Man* people = new Man[size + 1];
	for (int i = 0; i < size; i++) {
		strcpy(people[i].surname, man[i].surname);
		strcpy(people[i].name, man[i].name);
		people[i].years = man[i].years;
		people[i].data = man[i].data;
	}
	strcpy(people[size].surname, surname);
	strcpy(people[size].name, name);
	people[size].years = years;
	people[size].data = data;

	size++;
	delete[] man;
	return people;
}

Man* DeleteMan(Man man[], int& size, int index) {
	Man* people = new Man[size - 1];
	int a = 0;
	for (int i = 0; i < size; i++) {
		if (i != index) {
			strcpy(people[a].surname, man[i].surname);
			strcpy(people[a].name, man[i].name);
			people[a].years = man[i].years;
			people[a].data = man[i].data;
			a++;
		}
	}
	size--;
	delete[] man;
	return people;
}

Man* SearchigName(Man man[], int size, char name[], int& size1) {
	size1 = 0; int a = 0;
	for (int i = 0; i < size; i++) {
		if (strcmp(man[i].name, name) == 0) {
			size1++;
		}
	}
	Man* people = new Man[size1];
	for (int i = 0; i < size; i++) {
		if (strcmp(man[i].name, name) == 0) {
			strcpy(people[a].surname, man[i].surname);
			strcpy(people[a].name, man[i].name);
			people[a].years = man[i].years;
			people[a].data = man[i].data;
			a++;
		}
	}
	return people;
}

Man* SearchigSurname(Man man[], int size, char surname[], int& size1) {
	size1 = 0; int a = 0;
	for (int i = 0; i < size; i++) {
		if (strcmp(man[i].surname, surname) == 0) {
			size1++;
		}
	}
	Man* people = new Man[size1];
	for (int i = 0; i < size; i++) {
		if (strcmp(man[i].surname, surname) == 0) {
			strcpy(people[a].surname, man[i].surname);
			strcpy(people[a].name, man[i].name);
			people[a].years = man[i].years;
			people[a].data = man[i].data;
			a++;
		}
	}
	return people;
}

Man* Change(Man man[], int size, Man people, int index) {
	for (int i = 0; i < size; i++) {
		if (i == index) {
			strcpy(man[i].surname, people.surname);
			strcpy(man[i].name, people.name);
			man[i].years = people.years;
			man[i].data = people.data;
		}
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

	int a = 1, index; Man* shenninniks = new Man[size]; int month, size1 = 0; bool q;
	Man* searching = new Man[size1]; Man man;
	while (a != 9) {
		cout << "Select\n1 - sorting for name\n2 - sorting for surname\n3 - print\n4 - list shenninniks of the month\n5 - add man\n6 - delete man\n7 - searching\n8 - change\n9 - leave"; cin >> a;
		if (a == 1) {
			people = SortingName(people, size);
		}
		if (a == 2) {
			people = SortingSurname(people, size);
		}
		if (a == 3) {
			PrintMan(people, size);
		}
		if (a == 4) {
			cout << "Enter month"; cin >> month;
			shenninniks = listShenninniks(people, size, month, size1);
			PrintMan(shenninniks, size1);
		}
		if (a == 5) {
			cout << "Enter surname "; cin >> surname;
			cout << "Enter name "; cin >> name;
			cout << "Enter years "; cin >> years;
			cout << "Enter your birthday date "; cin >> data.day >> data.month >> data.year;
			people = AddMan(people, size, surname, name, years, data);
		}
		if (a == 6) {
			cout << "Which man?"; cin >> index;
			people = DeleteMan(people, size, index - 1);
		}
		if (a == 7) {
			cout << "Searching acording to\n0 - name\n1 - surname"; cin >> q;
			if (q == 0) {
				cout << "Enter name "; cin >> name;
				searching = SearchigName(people, size, name, size1);
				if (size1 > 0) {
					PrintMan(searching, size1);
				}
			}
			else {
				cout << "Enter surname "; cin >> surname;
				searching = SearchigSurname(people, size, surname, size1);
				if (size1 > 0) {
					PrintMan(searching, size1);
				}
				else {
					cout << "This surname is not searched\n";
				}
			}

		}
		if (a == 8) {
			cout << "Which man?"; cin >> index;
			cout << "Enter surname "; cin >> man.surname;
			cout << "Enter name "; cin >> man.name;
			cout << "Enter years "; cin >> man.years;
			cout << "Enter your birthday date "; cin >> man.data.day >> man.data.month >> man.data.year;
			people = Change(people, size, man, index - 1);
		}
	}
	delete[] people, shenninniks, searching;
	return 0;
}