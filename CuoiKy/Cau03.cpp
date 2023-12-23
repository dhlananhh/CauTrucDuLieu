#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>


struct ThongTin {
	char maSV[10];
	char hoSV[20];
	char tenSV[30];
	float diemCK;
	char lop[20];
};


struct node {
	ThongTin data;
	node *link;
};


struct list {
	node *first;
	node *last;
};


void init (list &L);
node *TaoNode (ThongTin x);
void themDau (list &L, ThongTin x);
void nhap1sv (ThongTin &x);
void xuat1sv (ThongTin x);
void nhapDS (list &L);
void xuatDS (list L);
void tachDS (list L, list &L1);


int main() {
	list L1, L2;
	init(L1);
	init(L2);
	
	nhapDS(L1);
	xuatDS(L1);
	tachDS(L1, L2);
	xuatDS(L23);
	
	return 0;
}


void init (list &L) {
	L.first = L.last = NULL;
}


node *TaoNode (ThongTin x) {
	node *p = new node;
	
	if (p == NULL)
		return NULL;
		
	p->data = x;
	p->link = NULL;
	return p;
}


void themDau (list &L, ThongTin x) {
	node *p = TaoNode(x);
	
	if (L.first == NULL) {
		L.first = L.last = p;
	} else {
		p->link = L.first;
		L.first = p;
	}
}


void themCuoi (list &L, ThongTin x) {
	node *p = TaoNode(x);
	
	if (L.first == NULL) {
		L.first = L.last = p;
	} else {
		L.last->link = p;
		L.last = p;
	}
}


void nhap1sv (ThongTin &x) {
	printf("\nNhap vao ma sinh vien: ");
	fflush(stdin);
	gets(x.maSV);
	
	printf("\nNhap vao ho sinh vien: ");
	fflush(stdin);
	gets(x.hoSV);
	
	printf("\nNhap vao ten sinh vien: ");
	fflush(stdin);
	gets(x.tenSV);
	
	printf("\nNhap vao diem cuoi ky: ");
	scanf("%f", &x.diemCK);
	
	printf("\nNhap vao ten lop: ");
	fflush(stdin);
	gets(x.lop);
}


void xuat1sv (ThongTin x) {
	printf("\n%-15s | %-20s | %-20s | %-15.2f | %-20s", x.maSV, x.hoSV, x.tenSV, x.diemCK, x.lop);
}


void nhapDS (list &L) {
	ThongTin x;
	int n;
	
	printf("\nNhap vao so luong sinh vien: ");
	scanf("%d", &n);
	
	for (int i=0; i<n; i++) {
		printf("\nNhap vao thong tin sinh vien thu %d: ", i+1);
		nhap1sv(x);
		themDau(L, x);
	}
}


void xuatDS (list L) {
	printf("\n%-15s | %-20s | %-20s | %-15s | %-20s", "Ma SV", "Ho SV", "Ten SV", "Diem CK", "Lop");
	
	node *p = L.first;
	while (p != NULL) {
		xuat1sv(p->data);
		p = p->link;
	}
}


void tachDS (list L, list &L1) {
	node *p = L.last;
	while (p != NULL) {
		themCuoi(L, p->data);
		p = p->link;
	}
}