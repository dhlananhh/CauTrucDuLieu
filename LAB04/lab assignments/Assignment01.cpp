#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define max 20


struct Stack {
	int items[max];
	int top;
} s;


void push (int x);
void pop();
int isEmpty();
void display();
int menu();


int main() {
	menu();
	return 0;
}


int menu() {
	Stack s;
	int choice, x;
	
	while (true) {
		printf("\n1. Push");
		printf("\n2. Pop");
		printf("\n3. Display");
		printf("\n4. Quit");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		
		switch (choice) {
			case 1:
				printf("\nEnter data: ");
				scanf("%d", &x);
				push(x);
				getch();
				break;
				
			case 2:
				pop();
				getch();
				break;
				
			case 3:
				display();
				getch();
				break;	
			
			case 4:
				printf("\nQuit");
				getch();
				break;
			
			default:
				printf("\nNo more options");
				getch();
				break;
		}
	}
	return 0;
}


void push (int x) {
	if (s.top == max-1)
		printf("\nOverflow");
	else {
		s.top = s.top+1;
		s.items[s.top] = x;
	}
}


void pop() {
	if (s.top == -1)
		printf("\nUnderflow");
	else
		s.top = s.top - 1;
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
