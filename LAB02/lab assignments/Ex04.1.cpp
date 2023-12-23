#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define max 100


struct Employee {
	char name[20];
	double salary;
};


void input (Employee list[], int &n);
void output (Employee list[], int n);
void InsertionSort (Employee list[], int n);


int main() {
	Employee list[max];
	int n;
	
	printf("\nNhap danh sach nhan vien: ");
	input(list, n);
	
	InsertionSort(list, n);
	printf("\nDanh sach nhan vien sau khi sap xep la: ");
	output(list, n);
	return 0;
}


void input (Employee list[], int &n) {
	printf("\nNhap vao so luong nhan vien: ");
	scanf("%d", &n);
	for (int i=0; i<n; i++) {
		printf("\nNhap vao ten nhan vien thu %d: ", i+1);
		fflush(stdin);
		gets(list[i].name);
		
		printf("\nNhap vao tien luong cua nhan vien thu %d: ", i+1);
		scanf("%lf", &list[i].salary);
	}
	
}


void output (Employee list[], int n) {
	printf("\n%5s|%20s|%10s", "No.", "Name", "Salary");
	for (int i=0; i<n; i++) {
		printf("\n%5d|%20s|%10.2f", i+1, list[i].name, list[i].salary);
	}
}


void InsertionSort (Employee list[], int n) {
	double x;
	int pos;
	
	for (int i=1; i<n; i++) {
		x = list[i].salary;
		pos = i-1;
						
		while (pos>=0 && list[pos].salary>x) {
			list[pos+1] = list[pos];
			pos--;
		}
		list[pos+1].salary = x;
	}
}