#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define max 100


struct Employee {
	char Name[20];
	double Salary;
};


void randName (char name[], int k);
void input_one (Employee &e);
void output_one (Employee list[], int i);
void input_list (Employee list[], int &n);
void output_list (Employee list[], int n);
void InsertionSort (Employee list[], int n);


int main() {
	Employee list[max];
	int n;
	
	printf("\nNhap danh sach nhan vien: ");
	input_list(list, n);
	
	InsertionSort(list, n);
	printf("\nDanh sach nhan vien sau khi sap xep la: ");
	output_list(list, n);
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


void input_one (Employee &e) {
	//randome ten nv
	randName(e.Name, 2+rand()%5);
		
	//random tien luong cua nv
	e.Salary = rand()%999;
}


void output_one (Employee list[], int i) {
	printf("\n%5d|%20s|%10.2f", i+1, list[i].Name, list[i].Salary);
}


void input_list (Employee list[], int &n) {
	printf("\nNhap vao so luong nhan vien: ");
	scanf("%d", &n);
	
	srand((int)time(NULL));
	for (int i=0; i<n; i++) {
		input_one(list[i]);
	}
}


void output_list (Employee list[], int n) {
	printf("\n%5s|%10s|%20s|%10s", "No.", "RollNo", "Name", "Salary");
	for (int i=0; i<n; i++) {
		printf("\n%5d|%20s|%10.2f", i+1, list[i].Name, list[i].Salary);
	}
}


void InsertionSort (Employee list[], int n) {
	double x;
	int pos;
	
	for (int i=1; i<n; i++) {
		x = list[i].Salary;
		pos = i-1;
						
		while (pos>=0 && list[pos].Salary>x) {
			list[pos+1] = list[pos];
			pos--;
		}
		list[pos+1].Salary = x;
	}
}