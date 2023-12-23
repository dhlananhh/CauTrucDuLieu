/* LAB ASSIGNMENT WEEK 4
4.4.2. Formulate a program to reverse a list of numbers using stack
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 20


struct Stack {
	int stack[max];
	int top;
};


void init (Stack &s);
int isEmpty (Stack s);
int isFull (Stack s);
void push (Stack &s, int x);
int pop (Stack &s);
int top (Stack &s);
void input (Stack &s, int n);
void display (Stack s);
void reverse (Stack s);


int main() {
	Stack s;
	int n;
	
	printf("\nInput array: ");
	printf("\nInput n: ");
	scanf("%d", &n);
	
	init(s);
	input(s, n);
	
	printf("\nArray after inputted: ");
	display(s);
	
	printf("\nArray after reversed: ");
	reverse(s);
	
	return 0;
}


void init (Stack &s) {
	s.top = -1;
}


int isEmpty (Stack s) {
	if (s.top == -1)
		return 1;
	else
		return 0;
}


int isFull (Stack s) {
	if (s.top == max-1)
		return 1;
	else
		return 0;
}


void push (Stack &s, int x) {
	if (isFull(s)==0) {
		s.top++;
		s.stack[s.top] = x;
	}
}


int pop (Stack &s) {
	int x;
	if (!isEmpty(s)) {
		x = s.stack[s.top];
		s.top--;
	}
	return x;
}


int top (Stack &s) {
	int x;
	if (!isEmpty(s)) {
		x = s.stack[s.top];
		return x;
	} else {
		return NULL;
	}
}


void input (Stack &s, int n) {
	for (int i=0; i<n; i++) {
		int x;
		printf("\nEnter element no. %d: ", i);
		scanf("%d", &x);
		push(s, x);
	}
}


void display (Stack s) {
	for (int i=0; i<=s.top; i++)
		printf("\n%d", s.stack[i]);
}


void reverse (Stack s) {
	for (int i=s.top; i>-1; i--) {
		printf("\n%d", s.stack[i]);
	}
}