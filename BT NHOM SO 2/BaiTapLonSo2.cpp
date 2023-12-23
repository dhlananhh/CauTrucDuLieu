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


int menu();
void createListDL (listDL &l);
void createListTP (listTP &L);
nodeDL *createNodeDL (dl x);
nodeTP *createNodeTP (tp x);
void nhap1DaiLy (dl &x);
void xuat1DaiLy (dl x);
void nhap1ThanhPho (tp &x);
void xuat1ThanhPho (nodeTP *k);
void inputListTP (listTP &L);
void outputListTP (listTP L);
void sapXepDSTheoDoanhThu (listDL &l);
void addTailDL (listDL &l, dl x);
void addHeadTP (listTP &L, listDL l, tp x);
void addTailTP (listTP &L, listDL l, tp x);
nodeTP *timThanhPho (listTP L, char tentp[]);
nodeDL *timDaiLy (listTP L, char tendl[], char tentp[]);
bool suaDaiLy (listTP &L, listDL &l, char tendl[], char tentp[]);
bool xoaDaiLy (listTP &L, listDL &l, char tendl[], char tentp[]);
bool themDaiLy (listTP &L, listDL &l, char tentp[]);
long timMinDoanhThu (listTP L);
void xuatDSMinDoanhThu (listTP L);
long timMaxDoanhThu (listTP L);
void xuatDSMaxDoanhThu (listTP L);
long xuatTongDoanhThu (listTP L);
long xuatTrungBinhDoanhThu (listTP L);


int main() {
	menu();
	return 0;
}


int menu() {
	listTP L;
	createListTP(L);
	listDL l;
	createListDL(l);
	
	nodeDL *p = new nodeDL;
	char tentp[50], tendl[50];
	int c;
	bool flag = true;
	
	do {
		printf("\nMENU QUAN LY CAC DAI LY TAI CAC THANH PHO");
		printf("\n\t1. Nhap danh sach thanh pho");
		printf("\n\t2. In danh sach");
		printf("\n\t3. Tim 1 dai ly");
		printf("\n\t4. Sua 1 dai ly");
		printf("\n\t5. Xoa 1 dai ly");
		printf("\n\t6. Them 1 dai ly");
		printf("\n\t7. Tim dai ly co doanh thu nho nhat");
		printf("\n\t8. Tim dai ly co doanh thu lon nhat");
		printf("\n\t9. Xuat tong doanh thu cua cac dai ly");
		printf("\n\t10. Xuat trung binh doanh thu cua cac dai ly");
		printf("\n\t11. Thoat");
		
		printf("\nNhap lua chon: ");
		scanf("%d", &c);
		
		switch (c) {
			case 0:
				flag = false;
				break;
				
			case 1:
				printf("\n1. Nhap danh sach thanh pho");
				inputListTP(L);
				getch();
				break;
				
			case 2:
				printf("\n2. In danh sach");
				outputListTP(L);
				getch();
				break;
			
			case 3:
				printf("\n3. Tim 1 dai ly");
				
				printf("\nNhap ten thanh pho can tim: ");
				fflush(stdin); 
				gets(tentp);
				
				printf("\nNhap ten dai ly can tim: "); 
				fflush(stdin); 
				gets(tendl);
				
				p = timDaiLy(L, tendl, tentp);
				if (p == NULL)
					printf("\nKhong tim thay dai ly can tim");
				else
					xuat1DaiLy(p->data);
					
				getch();
				break;
				
			case 4:
				printf("\n4. Sua 1 dai ly");
				
				printf("\nNhap ten dai ly can sua: "); 
				fflush(stdin); 
				gets(tendl);
				
				printf("\nNhap ten thanh pho can sua: ");
				fflush(stdin); 
				gets(tentp);
				
				if (suaDaiLy(L, l, tendl, tentp) == true)
					printf("\nDa sua thanh cong");
				else
					printf("\nKhong tim thay dai ly can sua");
					
				getch();
				break;
			
			case 5:
				printf("\n5. Xoa 1 dai ly");
				
				printf("\nNhap ten dai ly can xoa: "); 
				fflush(stdin); 
				gets(tendl);
				
				printf("\nNhap ten thanh pho can xoa: ");
				fflush(stdin); 
				gets(tentp);
				
				if (xoaDaiLy(L, l, tendl, tentp) == true)
					printf("\nDa xoa thanh cong");
				else
					printf("\nKhong tim thay dai ly can xoa");
				
				getch();
				break;
				
			case 6:
				printf("\n6. Them 1 dai ly");
				
				printf("\nNhap ten thanh pho can them dai ly: ");
				fflush(stdin); 
				gets(tentp);
				
				if (themDaiLy(L, l, tentp) == true)
					printf("\nDa them thanh cong");
				else
					printf("\nKhong tim thay thanh pho can them");
				
				getch();
				break;
				
			case 7:
				printf("\n7. Tim dai ly co doanh thu nho nhat");
				printf("\nDai ly co doanh thu nho nhat la: \n");
				xuatDSMinDoanhThu(L);
				getch();
				break;
			
			case 8:
				printf("\n8. Tim dai ly co doanh thu lon nhat");
				printf("\nDai ly co doanh thu lon nhat la: \n");
				xuatDSMaxDoanhThu(L);
				getch();
				break;
				
			case 9:
				printf("\n9. Xuat tong doanh thu cua cac dai ly");
				printf("\nTong doanh thu cua cac dai ly la: %ld\n", xuatTongDoanhThu(L));
				getch();
				break;
				
			case 10:
				printf("\n10. Xuat trung binh doanh thu cua cac dai ly");
				printf("\nTrung binh doanh thu cua cac dai ly la: %ld\n", xuatTrungBinhDoanhThu(L));
				getch();
				break;
		
			case 11:
				printf("\n11. Thoat");
				flag = false;
				getch();
				break;
				
			default:
				printf("\nChuong trinh khong co chuc nang nay");
				flag = false;
				getch();
				break;
		}
	} while (flag);
	
	return 0;
}


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
	printf("\nTen dai ly: ");
	puts(x.tenDL);
	
	printf("\nDoanh thu: %ld", x.doanhThu);
	
	printf("\nSo dien thoai: ");
	puts(x.sdt); 
}


void nhap1ThanhPho (listDL &l) {
	int m;
	dl x;
	
	printf("\nNhap so dai ly: ");
	scanf("%d", &m);
	
	for (int i=0; i<m; i++) {
		printf("\nNhap thong tin dai ly thu %d: ", i+1);
		nhap1DaiLy(x);
		addTailDL(l, x);
	}
}


void xuat1ThanhPho (nodeTP *k) {
	nodeDL *p;
	p = k->down;
	
	while (p != NULL) {
		xuat1DaiLy(p->data);
		p = p->tiep;
	}
}


void inputListTP (listTP &L) {
	int n;
	tp x;
	listDL l;
	
	printf("\nNhap so thanh pho: ");
	scanf("%d", &n);
	
	for (int i=0; i<n; i++) {
		printf("\nNhap thanh pho thu %d: ", i+1);
		printf("\nNhap ten thanh pho: ");
		fflush(stdin);
		gets(x.tenTP);
		createListDL(l);
		nhap1ThanhPho(l);
		sapXepDSTheoDoanhThu(l);
		addTailTP(L, l, x);
	}
}


void outputListTP (listTP L) {
	nodeTP *p = L.headTP;
	
	while (p != NULL) {
		printf("\nTen thanh pho: ");
		puts(p->data.tenTP);
		xuat1ThanhPho(p);
		p = p->next;
	}
}


void sapXepDSTheoDoanhThu (listDL &l) {
	for (nodeDL *p = l.headDL; p != l.tailDL; p = p->tiep)
		for (nodeDL *q = p->tiep; q != NULL; q = q->tiep)
			if (p->data.doanhThu > q->data.doanhThu) {
				nodeDL *temp;
				temp->data = p->data;
				p->data = q->data;
				q->data = temp->data;
			}
}

/*
void sapXepDSTheoTenThanhPho (listTP &L) {
	for (nodeTP *p = L.headTP; p != L.tailTP; p = p->next)
		for (nodeTP *q = p->next; q != NULL; q = q->next)
			if (strcmp(p->data.tenTP, q->data.tenTP)<0) {
				nodeTP *temp;
				temp->data = p->data;
				p->data = q->data;
				q->data = temp->data;
			}
}
*/


void addTailDL (listDL &l, dl x) {
	nodeDL *p = createNodeDL(x);
	
	if (l.headDL == NULL) {
		l.headDL = l.tailDL = p;
	} else {
		l.tailDL->tiep = p;
		l.tailDL = p;
	}
}


void addHeadTP (listTP &L, listDL l, tp x) {
	nodeTP *p = createNodeTP(x);
	
	if (L.headTP == NULL) {
		L.headTP = L.tailTP = p;
	} else {
		p->next = L.headTP;
		L.headTP = p;
		L.headTP->down = l.headDL;
	}
}


void addTailTP (listTP &L, listDL l, tp x) {
	nodeTP *p = createNodeTP(x);
	
	if (L.headTP == NULL) {
		L.headTP = L.tailTP = p;
		L.tailTP->down = l.headDL;
	} else {
		L.tailTP->next = p;
		L.tailTP = p;
		L.tailTP->down = l.tailDL;
	}
}


nodeTP *timThanhPho (listTP L, char tentp[]) {
	for (nodeTP *p = L.headTP; p != NULL; p = p->next)
		if (strcmp(p->data.tenTP, tentp)==0)
			return p;
	return NULL;
}


nodeDL *timDaiLy (listTP L, char tendl[], char tentp[]) {
	nodeTP *k = timThanhPho(L, tentp);
	
	for (nodeDL *p = k->down; p != NULL; p = p->tiep)
		if (strcmp(p->data.tenDL, tendl)==0)
			return p;
	return NULL;
}


bool suaDaiLy (listTP &L, listDL &l, char tendl[], char tentp[]) {
	nodeDL *k = timDaiLy(L, tendl, tentp);

	if (k == NULL) {
		return false;
	} else {
		printf("\nNhap ten dai ly moi: ");
		fflush(stdin);
		gets(k->data.tenDL);
		
		printf("\nNhap doanh thu moi: ");
		scanf("%ld", &k->data.doanhThu);
		
		printf("\nNhap sdt moi: ");
		fflush(stdin);
		gets(k->data.sdt);
		
		return true;
	}
}


bool xoaDaiLy (listTP &L, listDL &l, char tendl[], char tentp[]) {
	nodeDL *a = timDaiLy(L, tendl, tentp);
	
	if (a == NULL)
		return false;
	
	nodeTP *b = timThanhPho(L, tentp);
	if (a = b->down) {
		b->down = b->down->tiep;
		delete(b);
		return true;
	}
	
	nodeDL *prev = b->down;
	while (prev->tiep != a)
		prev = prev->tiep;
	prev = a->tiep;
	delete(a);
	
	return true;
}


bool themDaiLy (listTP &L, listDL &l, char tentp[]) {
	nodeTP *k = timThanhPho(L, tentp);
	
	if (k == NULL) {
		printf("\nKhong tim thay thanh pho");
		return false;
	} else {
		createListDL(l);
		nhap1ThanhPho(l);
		sapXepDSTheoDoanhThu(l);
		addTailTP(L, l, k->data);
		
		return true;
	}
}


long timMinDoanhThu (listTP L) {
	long min = L.headTP->down->data.doanhThu;
	nodeTP *p = L.headTP;
	
	while (p != NULL) {
		if (p->down->data.doanhThu < min)
			min = p->down->data.doanhThu;
		p = p->next;
	}
	
	return min;
}


void xuatDSMinDoanhThu (listTP L) {
	nodeTP *p = L.headTP;
	long min = timMinDoanhThu(L);
	
	while (p != NULL) {
		if (p->down->data.doanhThu == min)
			xuat1ThanhPho(p);
		p = p->next;
	}
}


long timMaxDoanhThu (listTP L) {
	long max = L.headTP->down->data.doanhThu;
	nodeTP *p = L.headTP;
	
	while (p != NULL) {
		if (p->down->data.doanhThu > max)
			max = p->down->data.doanhThu;
		p = p->next;
	}
	
	return max;
}


void xuatDSMaxDoanhThu (listTP L) {
	nodeTP *p = L.headTP;
	long max = timMaxDoanhThu(L);
	
	while (p != NULL) {
		if (p->down->data.doanhThu == max)
			xuat1ThanhPho(p);
		p = p->next;
	}
}


long xuatTongDoanhThu (listTP L) {
	long sum = 0;
	nodeTP *p = L.headTP;
	
	while (p != NULL) {
		sum += p->down->data.doanhThu;
		p = p->next;
	}
	
	return sum;
}


long xuatTrungBinhDoanhThu (listTP L) {
	long sum = 0, count = 0;
	nodeTP *p = L.headTP;
	
	while (p != NULL) {
		sum += p->down->data.doanhThu;
		count++;
		p = p->next;
	}
	
	return sum / count;
}

/*
int demSoLuongDaiLyTrongThanhPho (listTP L) {
	int count = 0;
	nodeTP *p = L.headTP;
	
	while (p != NULL) {
		if (p->down->data != NULL)
			count++;
	}
	return count;
}
*/
