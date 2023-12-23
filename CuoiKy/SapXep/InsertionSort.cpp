#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define max 100


void NhapMang (int a[], int &n);
void XuatMang (int a[], int n);
void InsertionSort (int a[], int n);


int main() {
	int a[max], n, x;
	
	printf("\nNhap mang: \n");
	NhapMang(a, n);
	
	printf("\nMang vua nhap la: \n");
	XuatMang(a, n);
	
	printf("\nMang sau khi sap xep Insertion Sort la: \n");
	InsertionSort(a, n);
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


void InsertionSort (int a[], int n) {
	for (int i=1; i<n; i++) {
		int x = a[i];
		int pos = i-1;
		
		while (pos>=0 && a[pos]>x) {
			a[pos+1] = a[pos];
			pos--;
		}
		a[pos+1]=x;
	}
}