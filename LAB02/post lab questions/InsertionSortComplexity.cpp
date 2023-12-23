#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define max 100


void InsertionSort (int a[], int n);


int main() {
	clock_t start_t, end_t, total_t;
	int a[max], n, i;
	
	
	start_t = clock();
	printf("\nBat dau chuong trinh, start_t = %ld\n", start_t);
	
	printf("\nSau khi thuc hien thuat toan sap xep Insertion Sort, start_t = %ld\n", start_t);
	for(i=0; i< 10000000; i++) {
		InsertionSort(a, n);
	}
	
	end_t = clock();
	printf("\nKet thuc vong lap, end_t = %ld\n", end_t);
	
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	printf("Tong thoi gian su dung boi CPU: %f\n", total_t  );
   	
	getch();
	printf("Thoat chuong trinh ...\n");
	
	return 0;
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