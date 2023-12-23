#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define max 100


void NhapMang (int a[], int &n);
void XuatMang (int a[], int n);
void QuickSort (int a[], int left, int right);
void swap (int &a, int &b);


int main() {
	int a[max], n;
	
	printf("\nNhap mang: \n");
	NhapMang(a, n);
	
	printf("\nMang vua nhap la: \n");
	XuatMang(a, n);
	
	QuickSort(a, 0, n-1);
	printf("\nMang sau khi sap xep Quick Sort la: \n");
	XuatMang(a, n);
	
	return 0;
}


void NhapMang (int a[], int &n) {
	printf("\nNhap vao so luong phan tu: ");
	scanf("%d", &n);
	
	for (int i=0; i<n; i++) {
		printf("\nNhap vao phan tu thu %d: ", i);
		scanf("%d", &a[i]);
	}
}


void XuatMang (int a[], int n) {
	for (int i=0; i<n; i++) {
		printf("\na[%d] = %d", i, a[i]);
	}
}


void QuickSort (int a[], int left, int right) {
	int pivot = a[(left+right)/2];
	int l = left, r = right;
	
	do {
		while (a[l] < pivot)
			l++;
		while (a[r] > pivot)
			r--;
			
		if (l <= r) {
			swap(a[l], a[r]);
			l++;
			r--;
		}
	} while (l <= r);
	
	if (left < r)
		QuickSort(a, left, r);
		
	if (l < right)
		QuickSort(a, l, right);
}


void swap (int &a, int &b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}