/*
	Compose a program to print odd nodes of a linked list
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
	int data;
	Node *link;	
};


struct SLL {
	Node *head, *tail;
};


void init (SLL &l);
Node *CreateNode (int x);
void addHead (SLL &l, Node *newEle);
Node *insertHead (SLL &l, int x);
void addTail (SLL &l, Node *newEle);
Node *insertTail (SLL &l, int x);
void inputList (SLL &l);
void outputList (SLL l);
void printOddNodes (SLL l);


int main() {
	SLL l;
	printf("\nInput SLL");
	inputList(l);
	
	
	printf("\nOdd nodes in SLL are: ");
	printOddNodes(l);
	outputList(l);
	
	return 0;
}


void init (SLL &l) {
	l.head = l.tail = NULL;
}


Node *CreateNode (int x) {
	Node *newEle;
	newEle = new Node;
	
	if (newEle == NULL)
		return NULL;
	
	newEle->data = x;
	newEle->link = NULL;
	return newEle;
}


void addHead (SLL &l, Node *newEle) {
	if (l.head == NULL) {
		l.head = newEle;
		l.tail = newEle;
	} else {
		newEle->link = l.head;
		l.head = newEle;
	}
}


Node *insertHead (SLL &l, int x) {
	Node *newEle = CreateNode(x);
	
	if (newEle == NULL)
		return NULL;
	
	addHead(l, newEle);
	return newEle;
}


void addTail (SLL &l, Node *newEle) {
	if (l.head == NULL) {
		l.head = newEle;
		l.tail = newEle;
	} else {
		l.tail->link = newEle;
		l.tail = newEle;
	}
}


Node *insertTail (SLL &l, int x) {
	Node *newEle = CreateNode(x);
	
	if (newEle == NULL)
		return NULL;
		
	addTail(l, newEle);
	return newEle;
}


void inputList (SLL &l) {
	Node *p;
	p = new Node;
	int n;
	
	printf("\nEnter the amounts of elements: ");
	scanf("%d", &n);
	
	for (int i=1; i<=n; i++) {
		printf("\nEnter the element no. %d: ", i);
		scanf("%d", &p->data);
		p = CreateNode(p->data);
		insertTail(l, p->data);
	}
}


void outputList (SLL l) {
	Node *p = l.head;
	
	while (l.head != NULL) {
		printf("%d\t", p->data);
		p = p->link;
	}
}


void printOddNodes (SLL l) {
	int counter = 0;
	Node *p = l.head;
	
	while (p != NULL) {
		if (counter % 2 == 1)
			printf("%d\t", p->data);
			
		counter++;		
		p = p->link;
	}
}
