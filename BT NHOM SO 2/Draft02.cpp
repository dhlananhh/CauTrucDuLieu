#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>


struct dl {
	char tenDL[50];
	char sdt[20];
	long doanhThu;
};


struct nodeDL {
	dl data;
	nodeDL *tiep;
};


struct listDL {
	nodeDL *headDL;
	nodeDL *tailDL;
};


struct tp {
	char tenTP[50];	
};


struct nodeTP {
	tp data;
	nodeTP *next;
	nodeDL *down;
};


struct listTP {
	nodeTP *headTP;
	nodeTP *tailTP;
};


//int menu();
void createListDL (listDL &l);
void createListTP (listTP &L);
nodeDL *createNodeDL (dl x);
nodeTP *createNodeTP (tp x);
void nhap1DaiLy (dl &x);
void xuat1DaiLy (dl x);
void nhap1ThanhPho (tp &x);
void xuat1ThanhPho (nodeTP *p);
void inputListTP (listTP &L);
void outputListTP (listTP L);
void interchangeSort (listDL &l);
nodeDL *addTailDL (listDL &l, dl x);
nodeTP *addTailTP (listTP &L, listDL l, tp x);
nodeTP *timThanhPho (listTP L, char ten[]);
void addDLToTP (char ten[]);


int main() {
//	menu();
	listTP L;
	
	inputListTP(L);
	outputListTP(L);
	
	return 0;
}


/*
int menu() {
	int c;
	bool flag = true;
	
	do {
		printf("\nMENU QUAN LY CAC DAI LY CUA CONG TY TAI CAC THANH PHO");
		printf("\n1. Them 1 thanh pho");
		printf("\n2. Them 1 dai ly vao 1 thanh pho");
		printf("\n3. Sua 1 dai ly");
		printf("\n4. Xoa 1 dai ly");
		printf("\n5. Tim kiem 1 1 dai ly");
		printf("\n6. In tat ca dai ly");
		printf("\n7. Thoat");
	} while (flag);
	
	return 0;
}
*/


void createListDL (listDL &l) {
	l.headDL = l.tailDL = NULL;
}


void createListTP (listTP &L) {
	L.headTP = L.tailTP = NULL;
}


nodeDL *createNodeDL (dl x) {
	nodeDL *p = new nodeDL;
	
	if (p==NULL) {
		printf("\nKhong du bo nho");
		return NULL;
	}
	
	p->data = x;
	p->tiep = NULL;
	return p;
}


nodeTP *createNodeTP (tp x) {
	nodeTP *q = new nodeTP;
	
	if (q==NULL) {
		printf("\nKhong du bo nho");
		return NULL;
	}
	
	q->data = x;
	q->next = NULL;
	q->down = NULL;
	return q;
}


void nhap1DaiLy (dl &x) {
	printf("\nNhap ten dai ly: ");
	fflush(stdin);
	gets(x.tenDL);
	
	printf("\nNhap doanh thu: ");
	scanf("%ld", &x.doanhThu);
	
	printf("\nNhap so dien thoai: ");
	fflush(stdin);
	gets(x.sdt);
}


void xuat1DaiLy (dl x) {
	printf("\n%-20s %15ld %-20s", x.tenDL, x.doanhThu, x.sdt);
}


void nhap1ThanhPho (tp &x) {
	printf("\nNhap ten thanh pho: ");
	fflush(stdin);
	gets(x.tenTP);
}


void xuat1ThanhPho (nodeTP *p) {
	nodeDL *q;
	q = p->down;
	
	while (q != NULL) {
		printf("\nTen thanh pho: ");
		puts(p->data.tenTP);
		xuat1DaiLy(q->data);
		q = q->tiep;
	}
}


void interchangeSort (listDL &l) {
	for (nodeDL *p = l.headDL; p != l.tailDL; p = p->tiep)
		for (nodeDL *q = p->tiep; q != NULL; q = q->tiep)
			if (p->data.doanhThu > q->data.doanhThu) {
				nodeDL *temp;
				temp->data = p->data;
				q->data = p->data;
				p->data = temp->data;
			}
}


nodeTP *timThanhPho (listTP L, char ten[]) {
	for (nodeTP *p = L.headTP; p != NULL; p = p->next)
		if (strcmp(p->data.tenTP, ten)==0)
			return p;
	return NULL;
}


nodeDL *addTailDL (listDL &l, dl x) {
	nodeDL *p = createNodeDL(x);
	
	if (l.headDL == NULL) {
		l.headDL = l.tailDL = p;
	} else {
		p->tiep = l.headDL;
		l.headDL = p;
	}
}


nodeTP *addTailTP (listTP &L, listDL l, tp x) {
	nodeTP *p = createNodeTP(x);
	
	if (L.headTP == NULL) {
		L.headTP = L.tailTP = p;
		L.tailTP->down = l.headDL;
	} else {
		L.tailTP->next = p;
		L.tailTP = p;
		L.tailTP->down = l.headDL;
	}
	
}


/*
void addDLToTP (listTP &L, char ten[]) {
	dl x;
	nodeTP *t = timThanhPho(L, ten);
	nodeDL *a = createNodeDL(x);
	
	if (t == NULL) {
		printf("\nKhong tim thanh pho");
	} else {
		addTailTP(L, l, x);
	}
}
*/


void inputListTP (listTP &L) {
	int n;
	tp x;
	listDL l;
	
	printf("\nNhap so luong thanh pho: ");
	scanf("%d", &n);
	
	for (int i=0; i<n; i++) {
		printf("\nNhap thanh pho thu %d: ", i+1);
		nhap1ThanhPho(x);
		createListDL(l);
		addTailTP(L, l, x);
		interchangeSort(l);
	}
}


void outputListTP (listTP L) {
	nodeTP *p = L.headTP;
	
	while (p != NULL) {
		xuat1ThanhPho(p);
		p = p->next;
	}
}
