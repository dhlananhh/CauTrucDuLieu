#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define max 100

void NhapMang (int a[], int &n);
void XuatMang (int a[], int n);
void SelectionSort (int a[], int n);
void swap (int &a, int &b);


int main() {
	int a[max], n;
	
	printf("\nNhap mang: \n");
	NhapMang(a, n);
	
	printf("\nMang vua nhap la: \n");
	XuatMang(a, n);
	
	SelectionSort(a, n);
	printf("\nMang sau khi sap xep Selection Sort la: \n");
	XuatMang(a, n);
	
	return 0;
}


void NhapMang (int a[], int &n) {
	printf("\nNhap vao so phan tu: ");
	scanf("%d", &n);
	
	srand(time(NULL));
	for (int i=0; i<n; i++) {
		a[i] = rand() % 100;
	}
}


void XuatMang (int a[], int n) {
	for (int i=0; i<n; i++) {
		printf("\na[%d] = %d", i, a[i]);
	}
}


void SelectionSort (int a[], int n) {
	int min;
	for (int i=0; i<n-1; i++) {
		min = i;
		for (int j=i+1; j<n; j++)
			if (a[j] < a[min])
				min = j;
		if (min != i)
			swap(a[min], a[i]);
	}
}


void swap (int &a, int &b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}