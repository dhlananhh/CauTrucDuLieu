#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>


struct MAT_HANG {
	char MaSP[9];
	char TenSP[30];
	int BaoHanh;
	char ChungLoai[15];
};


struct NODE {
	MAT_HANG info;
	NODE *pNext;
};


struct LIST {
	NODE *pHead;
	NODE *pTail;
};


void KhoiTao (LIST &L);
NODE *TaoNode (MAT_HANG mh);
void ThemDau (LIST &L, MAT_HANG mh);
void ThemCuoi (LIST &L, MAT_HANG mh);
void Nhap1MH (MAT_HANG &mh);
void Xuat1MH (MAT_HANG mh);
void NhapDanhSach (LIST &L);
void XuatDanhSach (LIST L);
void TachDanhSach (LIST L, LIST &L1, LIST &L2);


int main() {
	LIST L, L1, L2;
	KhoiTao(L);
	KhoiTao(L1);
	KhoiTao(L2);
	
	printf("\nNhap danh sach hang hoa: \n");
	NhapDanhSach(L);
	
	printf("\nDanh sach hang hoa sau khi nhap la: \n");
	XuatDanhSach(L);
	
	printf("\n\nDanh sach L sau khi tach la: \n\n");
	TachDanhSach(L, L1, L2);
	
	printf("\nDanh sach L1 la: \n");
	XuatDanhSach(L1);
	
	printf("\nDanh sach L2 la: \n");
	XuatDanhSach(L2);
	
	return 0;
}


void KhoiTao (LIST &L) {
	L.pHead = L.pTail = NULL;
}


NODE *TaoNode (MAT_HANG mh) {
	NODE *p = new NODE;
	
	if (p == NULL)
		return NULL;
		
	p->info = mh;
	p->pNext = NULL;
	return p;
}


void ThemCuoi (LIST &L, MAT_HANG mh) {
	NODE *p = TaoNode(mh);
	
	if (L.pHead == NULL) {
		L.pHead = L.pTail = p;
	} else {
		L.pTail->pNext = p;
		L.pTail = p;
	}
}


void Nhap1MH (MAT_HANG &mh) {
	printf("\nNhap vao ma san pham: ");
	fflush(stdin);
	gets(mh.MaSP);
	
	printf("\nNhap vao ten san pham: ");
	fflush(stdin);
	gets(mh.TenSP);
	
	printf("\nNhap vao thoi han bao hanh: ");
	scanf("%d", &mh.BaoHanh);
	
	printf("\nNhap vao chung loai: ");
	fflush(stdin);
	gets(mh.ChungLoai);
}


void Xuat1MH (MAT_HANG mh) {
	printf("\n%-15s | %-25s | %-15d | %-15s", mh.MaSP, mh.TenSP, mh.BaoHanh, mh.ChungLoai);
}


void NhapDanhSach (LIST &L) {
	MAT_HANG mh;
	int n;
	
	printf("\nNhap vao so luong mat hang: ");
	scanf("%d", &n);
	
	for (int i=0; i<n; i++) {
		printf("\nNhap vao thong tin mat hang thu %d: ", i+1);
		Nhap1MH(mh);
		ThemCuoi(L, mh);
	}
}


void XuatDanhSach (LIST L) {
	NODE *p = L.pHead;
	
	printf("\n%-15s | %-25s | %-15s | %-15s", "MaSP", "TenSP", "BaoHanh", "ChungLoai");
	
	while (p != NULL) {
		Xuat1MH(p->info);
		p = p->pNext;
	}
}


void XoaDanhSach (LIST &L) {
	NODE *p;
	
	while (L.pHead != NULL) {
		p = L.pHead;
		L.pHead = p->pNext;
		delete(p);
	}
	L.pTail = NULL;
}


void TachDanhSach (LIST L, LIST &L1, LIST &L2) {
	NODE *p = L.pHead;
	
	while (p != NULL) {
		if (strcmp(p->info.ChungLoai, "Giay")==0) {
			ThemCuoi(L1, p->info);
			p = p->pNext;
		} else {
			ThemCuoi(L2, p->info);
			p = p->pNext;
		}
	}
}