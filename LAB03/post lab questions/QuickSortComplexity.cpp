#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define max 100


void QuickSort (int a[], int left, int right);
void swap (int &a, int &b);


int main() {
	clock_t start_t, end_t, total_t;
	int a[max], n, i;
	
	
	start_t = clock();
	printf("\nBat dau chuong trinh, start_t = %ld\n", start_t);
	
	printf("\nSau khi thuc hien thuat toan sap xep Quick Sort, start_t = %ld\n", start_t);
	for(i=0; i< 10000000; i++) {
		QuickSort(a, 0, n-1);
	}
	
	end_t = clock();
	printf("\nKet thuc vong lap, end_t = %ld\n", end_t);
	
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	printf("Tong thoi gian su dung boi CPU: %f\n", total_t  );
   	
	getch();
	printf("Thoat chuong trinh ...\n");
	
	return 0;
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