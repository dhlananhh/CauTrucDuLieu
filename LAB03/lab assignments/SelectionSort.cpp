/* LAB 3
 Add the selection sort on the following elements: 21, 11, 5, 78, 49, 54, 72, 88
*/


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
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


void SelectionSort (int a[], int n) {
	for (int k=0; k<n-1; k++) {
		int min_pos = k;
		for (int i=k+1; i<n; i++)
			if (a[i] < a[min_pos])
				min_pos = i;
				
		swap(a[min_pos], a[k]);
	}
}


void swap (int &a, int &b) {
	int temp;
	temp = a;
	a = b;
	b = temp;
}