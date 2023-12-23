#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>


struct TNode {
	int key;
	TNode *left, *right;
};


void init (TNode *&tree);
TNode *createTNode (int x);
void insertTNode (TNode *&root, int x);
void createTree (TNode *&root);
void NLR (TNode *tree);


int main() {
	TNode *tree, *p;
	int x;
	
	init(tree);
	createTree(tree);
	NLR(tree);
	
	return 0;
}


void init (TNode *&tree) {
	tree = NULL;
}


TNode *createTNode (int x) {
	TNode *p = new TNode;
	
	if (p == NULL)
		return NULL;
	
	p->key = x;
	p->left = NULL;
	p->right = NULL;
	return p;
}


void insertTNode (TNode *&root, int x) {
	if (root == NULL) {
		TNode *q;
		q = new TNode;
		q->key = x;
		q->left = q->right = NULL;
		root = q;
	} else {
		if (x < root->key)
			insertTNode(root->left, x);
		else if (x > root->key)
			insertTNode(root->right, x);
	}
}


void createTree (TNode *&root) {
	int data;
	
	do{
		printf("Nhap vao du lieu, nhap -1 de ket thuc: ");
		scanf("%d", &data);
		if (data == -1)
			break;
		insertTNode(root, data);
	} while(1);
}


void NLR (TNode *tree) {
	if (tree != NULL) {
		printf("%d\t", tree->key);
		NLR(tree->left);
		NLR(tree->right);
	}
}