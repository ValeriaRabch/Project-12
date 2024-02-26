#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

struct Student {
	char surname[20], group[5];
	int marks[5];
};

int main() {
	//завдання 1
	int size = 5;
	Student* man = new Student[size];

	return 0;
}