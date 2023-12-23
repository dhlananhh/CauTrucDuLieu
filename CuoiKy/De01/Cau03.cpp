#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define max 100


struct SINHVIEN {
	char MaSV[9];
	char HoTen[30];
	float TichLuy;
	char XepLoai[15];
};


struct NODE {
	SINHVIEN data;
	NODE *link;
};


struct LIST {
	NODE *first;
	NODE *last;
	int tongSV;
};


void KhoiTao (LIST &L);
NODE *TaoNode (SINHVIEN sv);
void ThemDau (LIST &L, SINHVIEN sv);
void ThemCuoi (LIST &L, SINHVIEN sv);
void Nhap1SV (SINHVIEN &sv);
void Xuat1SV (SINHVIEN sv);
void NhapDanhSach (LIST &L);
void XuatDanhSach (LIST L);
int TongSV (LIST L);
int TinhTongSV (LIST L);
void XoaDanhSach (LIST &L);
void TachDanhSach (LIST L, LIST &L1, LIST &L2);


int main() {
	LIST L, L1, L2;
	KhoiTao(L);
	KhoiTao(L1);
	KhoiTao(L2);
	
	printf("\nNhap danh sach sinh vien: \n");
	NhapDanhSach(L);
	
	printf("\nXuat danh sach sinh vien vua nhap la: \n");
	XuatDanhSach(L);
	
	printf("\nTong sinh vien co trong danh sach la: %d\n", TongSV(L));
//	printf("\nTong sinh vien co trong danh sach la: %d\n", TinhTongSV(L));
	
	printf("\n\nDanh sach sinh vien sau khi tach la: \n\n");
	TachDanhSach(L, L1, L2);
	
	printf("\nDanh sach L1 la: \n");
	XuatDanhSach(L1);
	
	printf("\nDanh sach L2 la: \n");
	XuatDanhSach(L2);
	
	printf("\nDanh sach L sau khi xoa la: \n");
	XoaDanhSach(L);
	XuatDanhSach(L);
	
	return 0;
}


void KhoiTao (LIST &L) {
	L.first = L.last = NULL;
}


NODE *TaoNode (SINHVIEN sv) {
	NODE *p = new NODE;
	
	if (p == NULL)
		return NULL;
		
	p->data = sv;
	p->link = NULL;
	return p;
}


void ThemDau (LIST &L, SINHVIEN sv) {
	NODE *p = TaoNode(sv);
	
	if (L.first == NULL) {
		L.first = L.last = p;
	} else {
		p->link = L.first;
		L.first = p;
	}
}


void ThemCuoi (LIST &L, SINHVIEN sv) {
	NODE *p = TaoNode(sv);
	
	if (L.first == NULL) {
		L.first = L.last = p;
	} else {
		L.last->link = p;
		L.last = p;
	}
}


void Nhap1SV (SINHVIEN &sv) {
	printf("\nNhap vao ma sinh vien: ");
	fflush(stdin);
	gets(sv.MaSV);
	
	printf("\nNhap vao ho ten sinh vien: ");
	fflush(stdin);
	gets(sv.HoTen);
	
	printf("\nNhap vao diem tich luy: ");
	scanf("%f", &sv.TichLuy);
	
	printf("\nNhap vao xep loai hoc luc: ");
	fflush(stdin);
	gets(sv.XepLoai);
}


void Xuat1SV (SINHVIEN sv) {
	printf("\n%-15s | %-25s | %-15.2f | %-15s", sv.MaSV, sv.HoTen, sv.TichLuy, sv.XepLoai);
}


void NhapDanhSach (LIST &L) {
	SINHVIEN sv;
	int n;
	
	printf("\nNhap vao so luong sinh vien: ");
	scanf("%d", &n);
	
	for (int i=0; i<n; i++) {
		printf("\nNhap vao thong tin sinh vien thu %d: ", i+1);
		Nhap1SV(sv);
		ThemCuoi(L, sv);
		L.tongSV++;
	}
}


void XuatDanhSach (LIST L) {
	NODE *p = L.first;
	
	printf("\n%-15s | %-25s | %-15s | %-15s", "Ma SV", "Ho ten SV", "Tich luy", "Xep loai");
	
	while (p != NULL) {
		Xuat1SV(p->data);
		p = p->link;
	}
}


void XoaDanhSach (LIST &L) {
	NODE *p;
	
	while (L.first != NULL) {
		p = L.first;
		L.first = p->link;
		delete(p);
	}
	L.last = NULL;
}


void TachDanhSach (LIST L, LIST &L1, LIST &L2) {
	NODE *p = L.first;
	
	while (p != NULL) {
		if (strcmp(p->data.XepLoai, "Yeu")==0) {
			ThemCuoi(L1, p->data);
			p = p->link;
		} else {
			ThemCuoi(L2, p->data);
			p = p->link;
		}
	}
}


int TongSV (LIST L) {
	int dem = 0;
	NODE *p = L.first;
	
	while (p != NULL) {
		dem++;
		p = p->link;
	}
	
	return dem;
}


int TinhTongSV (LIST L) {
	return L.tongSV;
}