#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
	int ngay;
	int thang;
	int nam;
} Ngay;


typedef struct {
	char MaHang[10];
	char TenHang[50];
	Ngay NgayNhap;
	int SoLuong;
} MatHang;


void Nhap1MH (MatHang &mh);
void Xuat1MH (MatHang mh);
void NhapDSHangHoa (MatHang ds[], int &n);
void XuatDSHangHoa (MatHang ds[], int n);
int QuickSort (MatHang ds[], int left, int right);
void Swap (MatHang &a, MatHang &b);


int main() {
	MatHang ds[10000];
	int n;
	
	printf("\nNhap DS hang hoa: ");
	NhapDSHangHoa(ds, n);
	
//	printf("\nXuat DS hang hoa: ");
//	XuatDSHangHoa(ds, n);
	
	QuickSort(ds, 1, n-1);
	printf("\nDS hang hoa sau khi sap xep tang dan theo ma hang bang thuat toan Quick Sort la: ");
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


int QuickSort (MatHang ds[], int left, int right) {
	MatHang mh;
	int i, j;
	
	if (left >= right)
		return -1;
	
	i = left, j = right;
	mh = ds[(left+right)/2];
	
	do {
		while (strcmp(ds[i].MaHang, mh.MaHang)<0)
			i++;
		while (strcmp(ds[i].MaHang, mh.MaHang)>0)
			j--;
		if (i <= j) {
			Swap(ds[i], ds[j]);
			i++; j--;
		}
	} while (i<j);
	
	if (left < j)
		QuickSort(ds, left, j);
	if (right > i)
		QuickSort(ds, i, right);
}


void Swap (MatHang &a, MatHang &b) {
	MatHang temp;
	temp = a;
	a = b;
	b = temp;
}


void LinearSearch (MatHang ds[], int n, int x) {
	for (int i=0; i<n; i++) {
		if (ds[i].NgayNhap.thang == x)
			Xuat1MH(ds[i]);
	}
}