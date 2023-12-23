#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define max 100


void rand_text (int length, char *result);
int linearSearch (char *result, char c[]);


int main() {
	int length, result;
	char c[max];
		
	printf("\nNhap vao do dai chuoi: ");
	scanf("%d", &length);
	
	char str[length + 1];
	srand(time(NULL));
	rand_text(length, str);
	
	printf("\n%s", str);
	
	printf("\nNhap vao gia tri muon tim: ");
	scanf("%s", &c);

	result = linearSearch(str, c);
	if (result == NULL)
		printf("\nKHONG TIM THAY");
	else
		printf("\nGia tri muon tim nam o vi tri: %d", result);
	
	return 0;
}


void rand_text (int length, char *result) {
	int i, rand_int;
	char char_set[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz!@#$%^&*()_+<>?/[]";
	
	for (int i=0; i<length; i++)
		result[i] = char_set[rand() % sizeof(char_set)];
	
	result[length] = 0;
}


int linearSearch (char *result, char c[]) {
	int i, dem = 0;
	for (i=0; i<strlen(result); i++) {
		if (result[i] == c[0])
			return i;
	}
	return -1;
}