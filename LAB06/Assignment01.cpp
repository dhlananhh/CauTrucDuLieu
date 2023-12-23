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
void createListHead (SingleList &l, int n);
void addTail (SingleList &l, Node *newEle);
Node *insertTail (SingleList &l, int x);
void createListTail (SingleList &l, int n);
void addAfter (SingleList &l, Node *q, Node *newEle);
Node *insertAfter (SingleList &l, int x);
void removeHead (SingleList &l);
void removeAfter (SingleList &l, Node *q);
void removeTail (SingleList &l);
void removeMid (SingleList &l);
int totalNode (SingleList l);
void inputList (SingleList &l);
void outputList (SingleList l);
int menu();


int menu() {
	SingleList l;
	Node *t = new Node;
	int choice, n, k, v, i;
		
	while (true) {
		system("cls");
		printf("*******SINGLE LINKED LIST*******");
		printf("\n1. Insert at beginning");
		printf("\n2. Insert at middle");
		printf("\n3. Insert at end");
		printf("\n4. Delete at beginning");
		printf("\n5. Delete at middle");
		printf("\n6. Delete at end");
		printf("\n7. Traversal forward");
		printf("\n8. Count number of nodes");
		printf("\n9. Exit");
		
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		
		switch (choice) {
			case 1:
				printf("\n1. Insert at beginning");
				init(l);
				
				printf("\nInput: \n");
				inputList(l);
				
				printf("\nEnter data: ");
				scanf("%d", &k);
				insertHead(l, k);
				
				printf("\nOutput: \n");
				outputList(l);
				
				getch();
				break;
						
			case 2:
				printf("\n2. Insert at middle");
				init(l);
				
				printf("\nInput: \n");
				inputList(l);
				
				printf("\nEnter data: ");
				scanf("%d", &k);
				insertAfter(l, k);
				
				printf("\nOutput: \n");
				outputList(l);
				
				getch();
				break;
						
			case 3:
				printf("\n3. Insert at end");
				init(l);
				
				printf("\nInput: \n");
				inputList(l);
				
				printf("\nEnter data: ");
				scanf("%d", &k);
				insertTail(l, k);
				
				printf("\nOutput: \n");
				outputList(l);
				
				getch();
				break;

			case 4:
				printf("\n4. Delete at beginning");
				init(l);
				
				printf("\nInput: \n");
				inputList(l);
				
				removeHead(l);
				printf("\nOutput: \n");
				outputList(l);
				
				getch();
				break;
			
			case 5:
				printf("\n5. Delete at middle");
				init(l);
				
				printf("\nInput: \n");
				inputList(l);
				
				removeMid(l);
				printf("\nOutput: \n");
				outputList(l);
				
				getch();
				break;
			
			case 6:
				printf("\n6. Delete at end");
				init(l);
				
				printf("\nInput: \n");
				inputList(l);
				removeTail(l);
				
				printf("\nOutput: \n");
				outputList(l);
				
				getch();
				break;			
			
			case 7:
				printf("\n7. Traversal forward");
				init(l);
				
				printf("\nNhap DS: ");
				inputList(l);
				
				printf("\nDS vua nhap la: ");
				outputList(l);
				
				getch();
				break;	
								
			case 8:	
				printf("\n8. Count number of nodes");
				init(l);
				
				printf("\nNhap DS: ");
				inputList(l);
				
				printf("\nTong so node trong DS la: %d", totalNode(l));
				
				getch();
				break;
				
			case 9:
				printf("\nExit");
				getch();
				break;
							
			default:
				printf("\nNo more options");
				getch();
				break;
		}
	}
		
	return 1;
}


int main() {
	menu();
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


void removeTail (SingleList &l) {
	if (l.head != NULL) {
		Node *last = l.head;
		Node *prev = NULL;
		
		while (last->link != NULL) {
			prev = last;
			last = last->link;
		}
		
		prev->link = NULL;
		delete(last);
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


void removeMid (SingleList &l) {
	if (l.head != NULL) {
		Node *p = l.head;
		Node *prev = NULL;
		int count = totalNode(l);
		int mid = count / 2;
		
		while (p != NULL && p->data != mid) {
			prev = p;
			p = p->link;
		}
		
		if (p != NULL) {
			if (prev == NULL) {
				removeHead(l);
			} else {
				prev->link = p->link;
				p->link = NULL;
			}
		}
		
		delete(p);
	}
}


int totalNode (SingleList l) {
	Node *p = l.head;
	int count=1;
	
	while (p->link != NULL) {
		count++;
		p = p->link;
	}
	
	return count;
}


void inputList (SingleList &l) {
	Node *p;
	p = new Node;
	int n;
		
	printf("\nInput the amounts of elements: ");
	scanf("%d", &n);
	
	for (int i=1; i<=n; i++) {
		printf("\nEnter the element no. %d: ", i);
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
