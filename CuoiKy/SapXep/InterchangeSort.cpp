#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define max 100


void NhapMang (int a[], int &n);
void XuatMang (int a[], int n);
void InterchangeSort (int a[], int n);
void Swap (int &a, int &b);


int main() {
	int a[max], n, x;
	
	printf("\nNhap mang: ");
	NhapMang(a, n);
	
	printf("\nMang vua nhap la: \n");
	XuatMang(a, n);
	
	printf("\nMang sau khi sap xep Interchange Sort la: ");
	InterchangeSort(a, n);
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


void InterchangeSort (int a[], int n) {
	for (int i=0; i<n-1; i++)
		for (int j=i+1; j<n; j++)
			if (a[i] > a[j])
				Swap(a[i], a[j]);
}


void Swap (int &a, int &b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}