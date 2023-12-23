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


void input_one (Record &stud);
void output_one (Record list[], int i);
void randName (char name[], int k);
void input_list (Record list[]);
void output_list (Record list[]);
int searchByRollNo (Record list[], int n, int key);
int searchByName (Record list[], int n, char nameFound[]);
int searchByDOB (Record list[], int n, Date d, int a[]);


void input_one (Record &stud) {
	//random ten sv
	randName(stud.name, 2+rand()%5);
	
	//random rollno cua sv
	stud.RollNo = rand()%1000;
	
	//random nam sinh cua sv
	stud.dob.yy = rand()%99;
	
	//random thang sinh cua sv
	stud.dob.mm = 1+rand()%12;
	
	//random ngay thang sinh cua sv
	if (stud.dob.mm == 1 || stud.dob.mm == 3 || stud.dob.mm == 5 || stud.dob.mm == 7 || stud.dob.mm == 8 || stud.dob.mm == 10 || stud.dob.mm == 12)
		stud.dob.dd = 1+rand()%31;
	else if (stud.dob.mm == 4 || stud.dob.mm == 6 || stud.dob.mm == 9 || stud.dob.mm == 11)
		stud.dob.dd = 1+rand()%30;
	else
		stud.dob.dd = 1+rand()%28;
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


void input_list (Record list[]) {
	srand((int)time(NULL));
	for (int i=0; i<100; i++) {
		input_one(list[i]);
	}
}


void output_one (Record list[], int i) {
	printf("\n%-5d|%-10d|%-15s|%02d/%02d/%02d", i+1, list[i].RollNo, list[i].name, list[i].dob.dd, list[i].dob.mm, list[i].dob.yy);
}


void output_list (Record list[]) {
	printf("\n%-5s|%-10s|%-15s|%-30s", "No.", "RollNo", "Name", "Date of birth");
	for (int i=0; i<100; i++) {
		printf("\n%-5d|%-10d|%-15s|%02d/%02d/%02d", i+1, list[i].RollNo, list[i].name, list[i].dob.dd, list[i].dob.mm, list[i].dob.yy);
	}
}


int searchByRollNo (Record list[], Record t) {
	for (int i=0; i<100; i++) {
		if (list[i].RollNo == t.RollNo) {
			return i;
		}
	}
	return -1;
}


int searchByName (Record list[], Record t) {
	for (int i=0; i<100; i++)
		if (strcmp(list[i].name, t.name)==0)
			return i;
	return -1;
}


int searchByDOB (Record list[], Record t) {
	for (int i=0; i<100; i++) {
		if (list[i].dob.dd == t.dob.dd && list[i].dob.mm == t.dob.mm && list[i].dob.yy == t.dob.yy) {
			return i;
		}
	}
	return -1;
}


int main() {
	Record list[max], t;
	int n, x, k, i, f;
	
	input_list(list);
	output_list(list);
	
	printf("\nEnter the RollNo you want to find: ");
	scanf("%d", &t.RollNo);
	
	f = searchByRollNo(list, t);
	if (f==-1)
		printf("\nNot found");
	else
		output_one(list, f);

	printf("\nEnter the date of birth you want to find: ");
	scanf("%d/%d/%d", &t.dob.dd, &t.dob.mm, &t.dob.yy);
	
	k = searchByDOB(list, t);
	if (k==-1)
		printf("\nNot found");
	else {
		printf("\nThe element found at %d position: ", k);
		output_one(list, k);
	}
	
	printf("\nEnter the name you want to find: ");
	fflush(stdin);
	gets(t.name);
	
	x = searchByName(list, t);
	if (x==-1)
		printf("\nNot found");
	else
		output_one(list, x);
	
	return 0;
}