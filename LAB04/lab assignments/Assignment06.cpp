/* LAB ASSIGNMENT WEEK 4
4.4.6. Compose a program to implement Queue operations using arrays
*/


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define max 20


struct Queue {
	int items[max];
	int front;
	int rear;
} q;


void enQueue (int x);
void deQueue();
void display();
int isEmpty();
int menu();


int main() {
	menu();
	return 0;
}


int menu() {
	Queue q;
	int choice, x;
	
	while (true) {
		printf("\n1. Enqueue");
		printf("\n2. Dequeue");
		printf("\n3. Display");
		printf("\n4. Quit");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		
		switch (choice) {
			case 1:
				printf("\nEnter data: ");
				scanf("%d", &x);
				enQueue(x);
				getch();
				break;
		
			case 2:
				deQueue();
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


void enQueue (int x) {
	if (q.rear == max-1)
		printf("\nOverflow");
	else {
		q.rear++;
		q.items[q.rear] = x;
	}
}


void deQueue() {
	if (isEmpty())
		printf("\nUnderFlow");
	else {
		printf("\n%d removed from the queue", q.items[q.front]);
		q.front++;
	}
}


int isEmpty() {
	if (q.front > q.rear)
		return 1;
	else
		return 0;
}


void display() {
	for (int i=0; i<=q.rear; i++)
		printf("%d\t", q.items[i]);
}