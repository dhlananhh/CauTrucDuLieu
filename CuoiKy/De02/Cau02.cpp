#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define max 10000


struct Ngay {
	int ngay;
	int thang;
	int nam;
};


struct MatHang {
	char MaHang[10];
	char TenHang[50];
	Ngay NgayNhap;
	int SoLuong;
};


void Nhap1MH (MatHang &mh);
void Xuat1MH (MatHang mh);
void NhapDSHangHoa (MatHang ds[], int &n);
void XuatDSHangHoa (MatHang ds[], int n);
void BubbleSort (MatHang ds[], int n);
void swap (MatHang &a, MatHang &b);
void LinearSearch (MatHang ds[], int n, int x);


int main() {
	MatHang ds[max];
	int n;
	
	printf("\nNhap DS hang hoa: ");
	NhapDSHangHoa(ds, n);
	
	BubbleSort(ds, n);
	printf("\nDS hang hoa sau khi sap xep tang dan theo ma hang bang thuat toan Bubble Sort la: ");
	XuatDSHangHoa(ds, n);
	
	return 0;
}


void Nhap1MH (MatHang &mh) {
	printf("\nNhap vao ma hang: ");
	fflush(stdin);
	gets(mh.MaHang);
	
	printf("\nNhap vao ten hang: ");
	fflush(stdin);
	gets(mh.TenHang);
	
	printf("\nNhap vao ngay nhap: ");
	scanf("%d %d %d", &mh.NgayNhap.ngay, &mh.NgayNhap.thang, &mh.NgayNhap.nam);
	
	printf("\nNhap vao so luong: ");
	scanf("%d", &mh.SoLuong);
}


void Xuat1MH (MatHang mh) {
	printf("\n%-10s | %-15s | %d/%d/%d | %-10d", mh.MaHang, mh.TenHang, mh.NgayNhap.ngay, mh.NgayNhap.thang, mh.NgayNhap.nam, mh.SoLuong);
}


void NhapDSHangHoa (MatHang ds[], int &n) {
	do {
		printf("\nNhap n: ");
		scanf("%d", &n);
	} while (n<0);
		
	for (int i=0; i<n; i++) {
		printf("\nNhap thong tin mat hang thu %d: ", i+1);
		Nhap1MH(ds[i]);
	}
}


void XuatDSHangHoa (MatHang ds[], int n) {
	int stt = 1;
	
	printf("\n%-5s | %-10s | %-15s | %-8s | %-10s", "STT", "MaHang", "TenHang", "NgayNhap", "SoLuong");
	for (int i=0; i<n; i++)
		printf("\n%-5d | %-10s | %-15s | %d/%d/%d | %-10d", stt++, ds[i].MaHang, ds[i].TenHang, ds[i].NgayNhap.ngay, ds[i].NgayNhap.thang, ds[i].NgayNhap.nam, ds[i].SoLuong);
}


void BubbleSort (MatHang ds[], int n) {
	for (int i=0; i<n-1; i++) {
		for (int j=n-1; j>0; j--) {
			if (strcmp(ds[j-1].MaHang, ds[j].MaHang)>0)
				swap(ds[j], ds[j-1]);
		}
	}
}


void swap (MatHang &a, MatHang &b) {
	MatHang temp;
	temp = a;
	a = b;
	b = temp;
}


void LinearSearch (MatHang ds[], int n, int x) {
	for (int i=0; i<n; i++) {
		if (ds[i].NgayNhap.nam == x)
			Xuat1MH(ds[i]);
	}
}