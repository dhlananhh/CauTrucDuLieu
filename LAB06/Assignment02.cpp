/*
	Formulate a program to create a singly linked list and perform insertion, deletion, and travering operations on a singly linked list
*/


#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>


struct Node {
	int data;
	Node *link;
};

struct SingleList {
	Node *head;
	Node *tail;
};


void init (SingleList &l);
Node *CreateNode (int x);
void addHead (SingleList &l, Node *newEle);
Node *insertHead (SingleList &l, int x);
void addTail (SingleList &l, Node *newEle);
Node *insertTail (SingleList &l, int x);
void addAfter (SingleList &l, Node *q, Node *newEle);
Node *insertAfter (SingleList &l, int x);
void removeHead (SingleList &l);
void removeAfter (SingleList &l, Node *q);
void removeList (SingleList &l);
void inputList (SingleList &l);
void outputList (SingleList l);
void SingleListAppend(SingleList &l, SingleList &l2);


int main() {
	SingleList l, l2;
	init(l);
		
	inputList(l);
	SingleListAppend(l, l2);
	outputList(l2);
	
	return 0;
}


void init (SingleList &l) {
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


void addHead (SingleList &l, Node *newEle) {
	if (l.head == NULL) {
		l.head = newEle;
		l.tail = newEle;
	} else {
		newEle->link = l.head;
		l.head = newEle;
	}
}


Node *insertHead (SingleList &l, int x) {
	Node *newEle = CreateNode(x);
	
	if (newEle == NULL)
		return NULL;
		
	addHead(l, newEle);
	return newEle;
}


void addTail (SingleList &l, Node *newEle) {
	if (l.head == NULL) {
		l.head = newEle;
		l.tail = newEle;
	} else {
		l.tail->link = newEle;
		l.tail = newEle;
	}
}


Node *insertTail (SingleList &l, int x) {
	Node *newEle = CreateNode(x);
	
	if (newEle == NULL)
		return NULL;
	
	addTail(l, newEle);
	return newEle;
}


void addAfter (SingleList &l, Node *q, Node *newEle) {
	if (q != NULL && newEle != NULL) {
		newEle->link = q->link;
		q->link = newEle;
		
		if (q == l.tail)
			l.tail = newEle;
	} else {
		addHead(l, newEle);
	}
}


Node *insertAfter (SingleList &l, int x) {
	Node *newEle = CreateNode(x);
	Node *q = l.head;
	
	if (newEle == NULL)
		return NULL;
		
	addAfter(l, q, newEle);
	return newEle;
}


void removeHead (SingleList &l) {
	if (l.head != NULL) {
		Node *p = l.head;
		l.head = p->link;
		
		if (l.head == NULL)
			l.tail = NULL;
		
		delete(p);
	}
}


void removeAfter (SingleList &l, Node *q) {
	if (q != NULL && q->link != NULL) {
		Node *p = q->link;
		q->link = p->link;
		
		if (p == l.tail)
			l.tail = q;
			
		delete(p);
	}
}


void removeList (SingleList &l) {
	Node *p;
	
	while (l.head != NULL) {
		p = l.head;
		l.head = p->link;
		delete(p);
	}
	
	l.tail = NULL;
}


void inputList (SingleList &l) {
	Node *p;
	p = new Node;
	int n;
		
	printf("\nNhap so phan tu: ");
	scanf("%d", &n);
	
	for (int i=1; i<=n; i++) {
		printf("\nNhap phan tu thu %d: ", i);
		scanf("%d", &p->data);
		p = CreateNode(p->data);
		insertTail(l, p->data);
	}
}


void outputList (SingleList l) {
	Node *p = l.head;
	
	while (l.head != NULL) {
		printf("\t%d", p->data);
		p = p->link;
	}
}


void SingleListAppend(SingleList &l, SingleList &l2) {
	if (l2.head == NULL)
		return; 
	if (l.head == NULL) 
		l = l2;
	else {
		l.head->link = l2.head;
		l.tail = l2.tail;
	} 
	init(l2);
}
