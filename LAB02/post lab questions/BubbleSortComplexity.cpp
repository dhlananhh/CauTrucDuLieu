#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define max 100


void BubbleSort (int a[], int n);
void swap (int &a, int &b);


int main() {
	clock_t start_t, end_t, total_t;
	int a[max], n, i;
	
	
	start_t = clock();
	printf("\nBat dau chuong trinh, start_t = %ld\n", start_t);
	
	printf("\nSau khi thuc hien thuat toan sap xep Bubble Sort, start_t = %ld\n", start_t);
	for(i=0; i< 10000000; i++) {
		BubbleSort(a, n);
	}
	
	end_t = clock();
	printf("\nKet thuc vong lap, end_t = %ld\n", end_t);
	
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	printf("Tong thoi gian su dung boi CPU: %f\n", total_t  );
   	
	getch();
	printf("Thoat chuong trinh ...\n");
	
	return 0;
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