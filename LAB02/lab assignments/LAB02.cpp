#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define max 50


//Define
struct Record {
	char Name[10];
	int RollNo;
	double Salary;
	double Grade;
};


//Prototype
int menu();
void input_one (Record &r);
void input_oneStaff (Record &e);
void input_oneStudent (Record &s);

void output_one (Record list[], int i);
void output_oneStaff (Record listStaff[], int i);
void output_oneStudent (Record listStudent[], int i);

void randName (char name[], int k);
void swap (Record &a, Record &b);
void BubbleSortName (Record listStudent[]);
void BubbleSortGrade (Record listStudent[]);
void InsertionSortSalary (Record listStaff[]);

void input_list (Record list[]);
void input_listStaff (Record listStaff[]);
void input_listStudent (Record listStudent[]);

void output_list (Record list[]);
void output_listStaff (Record listStaff[]);
void output_listStudent (Record listStudent[]);


int menu() {
	Record list[max], listStaff[max], listStudent[max];
	int i, c;
	
	while (true) {
		system("cls");
		printf("LAB 2. SORTING TECHNIQUES");
		printf("\n3. Formulate a program to sort N names using Bubble Sort");
		printf("\n4. Write a program to sort N employee records based on their salary using insertion sort");
		printf("\n5. A class contains 50 students who acquired marks in 10 subjects. Write a program to display top 10 students roll numbers and marks in sorted order by using bubble sorting technique");
		
		printf("\nEnter your option: ");
		scanf("%d", &c);
		
		switch (c) {
			case 3:
				printf("\nYou chose option 3: ");
				input_list(list);
				BubbleSortName(list);
				output_list(list);
				getch();
				break;
				
			case 4:
				printf("\nYou chose option 4: ");
				input_listStaff(listStaff);
				InsertionSortSalary(listStaff);
				output_listStaff(listStaff);
				getch();
				break;
				
			case 5:
				printf("\nYou chose option 5: ");
				input_listStudent(listStudent);
				BubbleSortGrade(listStudent);
				output_listStudent(listStudent);
				getch();
				break;
			
			default:
				printf("\nNo more options");
				getch();
				break;
		}
	}
	
	return 0;
}


int main() {
	menu();
	return 0;
}


void randName (char name[], int k) {
	for (int i=0; i<k; i++) {
		if (i==0)
			name[i] = 65+rand()%25;
		else
			name[i] = 97+rand()%25;
	}
	name[k] = 0;
}


void swap (Record &a, Record &b) {
	Record t;
	t = a;
	a = b;
	b = t;
}


void BubbleSortName (Record listStudent[]) {
	for (int i=0; i<50-1; i++)
		for (int j=50; j>i; j--)
			if (strcmp(listStudent[j].Name, listStudent[j-1].Name)<0)
				swap(listStudent[j], listStudent[j-1]);
}


void BubbleSortGrade (Record listStudent[]) {
	for (int i=0; i<50-1; i++)
		for (int j=50; j>i; j--)
			if (listStudent[j].Grade < listStudent[j-1].Grade)
				swap(listStudent[j], listStudent[j-1]);
}


void InsertionSortSalary (Record listStaff[]) {
	for (int i=1; i<50; i++) {
		double x = listStaff[i].Salary;
		int pos = i-1;
		
		while (pos>=0 && listStaff[pos].Salary>x) {
			listStaff[pos+1].Salary = listStaff[pos].Salary;
			pos--;
		}
		listStaff[pos+1].Salary = x;
	}
}


void input_one (Record &r) {
	//random rollno
	r.RollNo = 1+rand()%1000;
	
	//random ten
	randName(r.Name, 2+rand()%5);
}


void input_oneStaff (Record &e) {
	//random rollno
	e.RollNo = 1+rand()%1000;
	
	//random ten
	randName(e.Name, 2+rand()%5);
	
	//random tien luong
	e.Salary = 1+rand()%999;
}


void input_oneStudent (Record &s) {
	//random rollno
	s.RollNo = 1+rand()%1000;
	
	//random ten
	randName(s.Name, 2+rand()%5);
	
	//random diem
	s.Grade = 1+rand()%10;
}


void output_one (Record list[], int i) {
	printf("\n%-5d|%-10d|%-15s", i+1, list[i].RollNo, list[i].Name);
}


void output_oneStaff (Record listStaff[], int i) {
	printf("\n%-5d|%-10d|%-15s|%-15.2f", i+1, listStaff[i].RollNo, listStaff[i].Name, listStaff[i].Salary);
}


void output_oneStudent (Record listStudent[], int i) {
	printf("\n%-5d|%-10d|%-15s", i+1, listStudent[i].RollNo, listStudent[i].Name);
}


void input_list (Record list[]) {
	srand((int)time(NULL));
	for (int i=0; i<50; i++) {
		input_one (list[i]);
	}
}


void input_listStaff (Record listStaff[]) {
	srand((int)time(NULL));
	for (int i=0; i<50; i++) {
		input_oneStaff (listStaff[i]);
	}
}


void input_listStudent (Record listStudent[]) {
	srand(time(NULL));
	for (int i=0; i<50; i++) {
		input_oneStudent (listStudent[i]);
	}
}


void output_list (Record list[]) {
	printf("\n%-5s|%-10s|%-15s", "No.", "RollNo", "Name");
	for (int i=0; i<50; i++) {
		printf("\n%-5d|%-10d|%-15s", i+1, list[i].RollNo, list[i].Name);
	}
}


void output_listStaff (Record listStaff[]) {
	printf("\n%-5s|%-10s|%-15s|%-15s", "No.", "RollNo", "Name", "Salary");
	for (int i=0; i<50; i++) {
		printf("\n%-5d|%-10d|%-15s|%-15.2f", i+1, listStaff[i].RollNo, listStaff[i].Name, listStaff[i].Salary);
	}
}


void output_listStudent (Record listStudent[]) {
	printf("\n%-5s|%-10s|%-15s|%-15s", "No.", "RollNo", "Name", "Grade");
	for (int i=0; i<50; i++) {
		printf("\n%-5d|%-10d|%-15s|%-15.2f", i+1, listStudent[i].RollNo, listStudent[i].Name, listStudent[i].Grade);
	}
}