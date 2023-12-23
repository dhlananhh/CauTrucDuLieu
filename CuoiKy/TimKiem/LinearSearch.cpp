/* LAB 1 - IMPLEMENTATION:
* Implementation of Linear Search
*/


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define max 100


void NhapMang (int a[], int &n);
void XuatMang (int a[], int n);
int linearSearch (int a[], int n, int x);


int main() {
	int a[max], n, x;
	
	printf("\nNhap mang: ");
	NhapMang(a, n);
	
	printf("\nMang vua nhap la: ");
	XuatMang(a, n);
	
	printf("\nNhap vao gia tri muon tim: ");
	scanf("%d", &x);
	
	printf("\nGia tri muon tim nam o vi tri: %d", linearSearch(a, n, x));
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


int linearSearch (int a[], int n, int x) {
	for (int i=0; i<n; i++)
		if (a[i] == x)
			return i;
	
	return -1;
}