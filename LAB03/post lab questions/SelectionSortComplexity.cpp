#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define max 100


void SelectionSort (int a[], int n);
void swap (int &a, int &b);


int main() {
	clock_t start_t, end_t, total_t;
	int a[max], n, i;
	
	
	start_t = clock();
	printf("\nBat dau chuong trinh, start_t = %ld\n", start_t);
	
	printf("\nSau khi thuc hien thuat toan sap xep Selection Sort, start_t = %ld\n", start_t);
	for(i=0; i< 10000000; i++) {
		SelectionSort(a, n);
	}
	
	end_t = clock();
	printf("\nKet thuc vong lap, end_t = %ld\n", end_t);
	
	total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
	printf("Tong thoi gian su dung boi CPU: %f\n", total_t  );
   	
	getch();
	printf("Thoat chuong trinh ...\n");
	
	return 0;
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