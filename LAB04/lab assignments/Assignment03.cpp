/* LAB ASSIGNMENT WEEK 4
4.4.1. Write a program to convert a number from decimal to binary using stack
*/


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define max 100


struct Stack {
	int a[max];
	int top;
};


void init (Stack &s);
void push (Stack &s, int x);
int pop (Stack &s);
bool isEmpty (Stack s);
bool isFull (Stack s);
void display (Stack s);
int top (Stack s);
void convertDecimalToBinary (int n);


int main() {
	int n;
	
	printf("Enter a number: ");
	scanf("%d", &n);
	
	convertDecimalToBinary(n);
	return 0;
}


void init (Stack &s) {
	s.top = -1;
}


void push (Stack &s, int x) {
	s.a[++s.top] = x;
}


int pop (Stack &s) {
	return s.a[s.top--];
}


int top (Stack s) {
	return s.top;
}


bool isEmpty (Stack s) {
	return s.top < 0;
}


bool isFull (Stack s) {
	return s.top == max;
}


void display (Stack s) {
	for (int i=0; i<=s.top; i++)
		printf("%d\t", s.a[i]);
	printf("\n");
}


void convertDecimalToBinary (int n) {
	Stack s;
	init(s);
	
	while (n != 0) {
		push(s, n%2);
		n/=2;
	}
	
	while (isEmpty(s)==false)
		printf("%d", pop(s));
	printf("\n");
}