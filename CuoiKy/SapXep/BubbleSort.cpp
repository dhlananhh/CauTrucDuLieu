#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define max 100


void NhapMang (int a[], int &n);
void XuatMang (int a[], int n);
void BubbleSort (int a[], int n);
void swap (int &a, int &b);


int main() {
	int a[max], n, x;
	
	printf("\nNhap mang: ");
	NhapMang(a, n);
	
	printf("\nMang vua nhap la: \n");
	XuatMang(a, n);
	
	printf("\nMang sau khi sap xep Bubble Sort la: ");
	BubbleSort(a, n);
	XuatMang(a, n);
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


void BubbleSort (int a[], int n) {
	for (int i=0; i<n-1; i++)
		for (int j=n-1; j>i; j--)
			if (a[j]<a[j-1])
				swap(a[j], a[j-1]);
}


void swap (int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}