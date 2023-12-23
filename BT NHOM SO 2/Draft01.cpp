#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>


//Khai bao cau truc du lieu cua bai toan
struct DL {
	char tenDL[50];
	char sdt[20];
	double doanhThu;	
};


struct nodeDL {
	DL data;
	nodeDL *tiep;
};


struct ListDL {
	nodeDL *head;
	nodeDL *tail;
};


struct TP {
	char tenTP[50];
};


struct nodeTP {
	TP info;
	nodeTP *next;
	nodeTP *down;
};


struct ListTP {
	nodeTP *pHead;
	nodeTP *pTail;
};


//Dai ly
void initListDL (ListDL &listDL);
nodeDL *createNodeDL (DL dl);
void nhap1DaiLy (DL &dl);
void xuat1DaiLy (DL dl);
void inputListDL (ListDL &listDL);
void outputListDL (ListDL listDL);
void addTailDL (ListDL &listDL, DL dl);


//Thanh pho
void initListTP (ListTP &listTP);
void nhap1ThanhPho (TP &tp);
void xuat1ThanhPho (TP tp);


//Quan ly



int main() {
	return 0;
}


void initListDL (ListDL &listDL) {
	listDL.head = listDL.tail = NULL;
}


void initListTP (ListTP &listTP) {
	listTP.pHead = listTP.pTail = NULL;
}


nodeDL *createNodeDL (DL dl) {
	nodeDL *p = new nodeDL;
	
	if (p==NULL)
		return NULL;
	
	p->data = dl;
	p->tiep = NULL;
	return p;
}


nodeTP *createNodeTP (TP tp) {
	nodeTP *q = new nodeTP;
	
	if (q==NULL)
		return NULL;
	
	q->info = tp;
	q->next = NULL;
	q->down = NULL;
	return q;
}


void addTailDL (ListDL &listDL, DL dl) {
	node *p = createNodeDL(dl);
	
	if (listDL.head == NULL) {
		listDL.head = p;
		listDL.tail = p;
	} else {
		listDL.tail->tiep = p;
		listDL.tail = p;
	}
}


void nhap1DaiLy (DL &dl) {
	printf("\nNhap ten dai ly: ");
	fflush(stdin);
	gets(dl.tenDL);
	
	printf("\nNhap doanh thu: ");
	scanf("%lf", &dl.doanhThu);
	
	printf("\nNhap so dien thoai: ");
	fflush(stdin);
	gets(dl.sdt);
}


void xuat1DaiLy (DL dl) {
	printf("\n%-20s %15.2f %-20s", dl.tenDL, dl.doanhThu, dl.sdt);
}


void inputListDL (ListDL &listDL) {
	DL dl;
	int n;
	
	printf("\nNhap so luong dai ly: ");
	scanf("%d", &n);
	
	for (int i=0; i<n; i++) {
		printf("\nNhap thong tin dai ly thu %d: ", i+1);
		nhap1DaiLy(dl);
		addTail(listDL, dl);
	}
}


void outputListDL (ListDL listDL) {
	printf("\n%-20s %15.2f %-20s", "Ten dai ly", "Doanh thu", "SDT");
	
	nodeDL *p = listDL.head;
	while (p != NULL) {
		xuat1DaiLy(p->data);
		p = p->tiep;
	}
}


nodeTP *createNodeTP (TP tp) {
	nodeTP *q = new nodeTP;
	
	if (q==NULL)
		return NULL;
	
	q->info = tp;
	q->next = NULL;
	q->down = NULL;
	return q;
}


void insertTail (ListTP &listTP, TP tp) {
	DL dl;
	nodeDL *p = createNodeDL(dl);
	nodeTP *q = createNodeTP(tp);
	
	if (listTP.pHead == NULL) {
		listTP.pHead = q;
		listTP.pTail = q;
	} else {
		listTP.pTail->next = q;
		q->down = p;
		listTP.pTail = q;
	}
}


void nhap1ThanhPho (TP &tp) {
	printf("\nNhap ten thanh pho: ");
	fflush(stdin);
	gets(tp.tenTP);
}


void xuat1ThanhPho (TP tp) {
	printf("\n%-20s", tp.tenTP);
}


void inputListTP (ListTP &listTP) {
	TP tp;
	int n;
	
	printf("\nNhap so luong thanh pho hien co: ");
	scanf("%d", &n);
	
	for (int i=0; i<n; i++) {
		printf("\nNhap thong tin thanh pho thu %d: ", i+1);
		nhap1TP(tp);
		insertTail(listTP, tp);
	}
}