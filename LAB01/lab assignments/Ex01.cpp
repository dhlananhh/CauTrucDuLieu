/* LAB 1 - LAB ASSIGNMENT
A person has registered for voter id, he received a voter number and he need to check whether it exist in the voter or not.
Use a binary searching in a recursive way to find whether the voter number exist in the list or not.
*/


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define max 100


void NhapMang (int a[], int &n);
void XuatMang (int a[], int n);
int binarySearch (int a[], int n, int x);


int main() {
	int a[max];
	int n = sizeof(a) / sizeof(a[0]);
	int x;
	
	printf("\nNhap mang: ");
	NhapMang(a, n);
	
	printf("\nMang vua nhap la: ");
	XuatMang(a, n);
	
	printf("\nNhap vao gia tri muon tim: ");
	scanf("%d", &x);

	int result = binarySearch(a, n, x);
	if (result == -1)
		printf("\nKHONG TIM THAY");
	else
		printf("\nGia tri muon tim nam o vi tri: %d", result);
	
	return 0;
}


void NhapMang (int a[], int &n) {
	printf("\nNhap vao so phan tu: ");
	scanf("%d", &n);
	
	srand(time(NULL));
	for (int i=0; i<n; i++)
		a[i] = rand() % 100;
}


void XuatMang (int a[], int n) {
	for (int i=0; i<n; i++)
		printf("\na[%d] = %d", i, a[i]);
}


int binarySearch (int a[], int n, int x) {
	int left = 0;
	int right = n-1;
	
	while (left <= right) {
		int mid = left + (left + right) / 2;
		if (a[mid] == x)
			return mid;
		else if (a[mid] > x)
			right = mid - 1;
		else
			left = mid + 1;
	}
	
	return -1;
}