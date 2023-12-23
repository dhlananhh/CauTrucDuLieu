#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 20


struct Stack {
	int items[max];
	int top;
} s;


void push (int x);
void pop();
int top();
int isEmpty();
void display();
int factorial (int x);
int factorial_number (int x);


int main() {
	Stack s;
	int n;
	
	printf("\nEnter a number: ");
	scanf("%d", &n);
	
	printf("\nFactorial number: %d", factorial(n));
	return 0;
}


void push (int x) {
	if (s.top == max-1)
		printf("\nOverflow");
	else {
		s.top++;
		s.items[s.top] = x;
	}
}


void pop() {
	if (s.top == -1)
		printf("\nUnderflow");
	else
		s.top--;
}


int top() {
	if (s.top == -1) {
		printf("\nUnderflow");
		return -1;
	} else
		return s.items[s.top];
}


int isEmpty() {
	if (s.top == -1)
		return 1;
	else
		return 0;
}


void display() {
	for (int i=0; i<=s.top; i++)
		printf("%d\t", s.items[i]);
	printf("\n");
}


int factorial (int x) {
	if (x==1)
		return 1;
	else
		return x*factorial(x-1);
}


void push_factorial (int x) {
	while (x != 0) {
        push(x%10);
        x/=10;
    }
}


int factorial_number (int x) {
	push_factorial(x);
	int f;
	
	while (!isEmpty()) {
		f*=top();
		pop();
	}
	
	return f;
}