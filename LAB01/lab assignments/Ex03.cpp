#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define max 100


struct Date {
	int dd, mm, yy;
};


struct Record {
	int RollNo;
	char name[20];
	struct Date dob;
};


void input_one (Record &stud) {
	printf("\nInput your code: ");
	scanf("%d", &stud.RollNo);
	
	printf("\nInput your name: ");
	fflush(stdin);
	gets(stud.name);
	
	printf("\nInput your date of birth: ");
	scanf("%d%d%d", &stud.dob.dd, &stud.dob.mm, &stud.dob.yy);
}

void input_list (Record list[], int &n) {
	printf("\nInput the amount of students: ");
	scanf("%d", &n);
	
	for (int i=0; i<n; i++) {
		printf("\nInput no. %d student's details: ");
		input_one(list[i]);
	}
}


//void output_one (Record stud) {
//	printf("\n%d\t%s\t%d/%d/%d", stud.RollNo, stud.name, stud.dob.dd, stud.dob.mm, stud.dob.yy);
//}


void output_list (Record list[], int n) {
	int num = 1;
	for (int i=0; i<n; i++) {
		printf("\n%d\t%d\t%s\t%d/%d/%d", num, list[i].RollNo, list[i].name, list[i].dob.dd, list[i].dob.mm, list[i].dob.yy);
	}
}


int searchDOB (Record list[], int n) {
	Date bd;
	printf("\nEnter the date of birth you want to find: ");
	scanf("%d%d%d", &bd.dd, &bd.mm, &bd.yy);
	
	for (int i=0; i<n; i++) {
		if ()
	}
}


int main() {
	return 0;
}