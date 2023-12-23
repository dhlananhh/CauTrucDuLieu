/* LAB 1 - IMPLEMENTATION:
* Implementation of Binary Search
*/


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define max 100


void NhapMang (int a[], int &n);
void SapXepMang (int a[], int n);
void XuatMang (int a[], int n);
int binarySearch (int a[], int n, int x);


int main() {
	int a[max], n, x;
	
	printf("\nNhap mang: ");
	NhapMang(a, n);
	
	printf("\nMang sau khi sap xep tang dan la: ");
	SapXepMang(a, n);
	XuatMang(a, n);
	
	printf("\nNhap vao gia tri muon tim: ");
	scanf("%d", &x);
	
	printf("\nGia tri muon tim nam o vi tri: %d", binarySearch(a, n, x));
	return 0;
	
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


void SapXepMang (int a[], int n) {
	int temp;
	for (int i=0; i<n-1; i++) {
		for (int j=i+1; j<n; j++) {
			if (a[i] > a[j]) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

int binarySearch (int a[], int n, int x) {
	int left = 0;
	int right = n-1;
	
	while (left <= right) {
		int mid = (left + right) / 2;
		if (a[mid] == x)
			return mid;
		else if (a[mid] > x)
			right = mid - 1;
		else
			left = mid + 1;
	}
	return -1;
}
