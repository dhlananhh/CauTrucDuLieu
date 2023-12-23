#include <stdio.h>

struct Date{
	int ngay,thang,nam;
};
struct HocSinh{
	int MS;
	char ten[20];
	Date NgaySinh;
};
void Nhap1HS(HocSinh &hs){
	printf("Ma so hoc sinh: "); scanf("%d", &hs.MS);
	fflush(stdin);
	printf("Ten hoc sinh: "); gets(hs.ten);
	printf("Ngay sinh (ngay/thang/nam): "); scanf("%d/%d/%d", &hs.NgaySinh.ngay, &hs.NgaySinh.thang, &hs.NgaySinh.nam);
}
void NhapDSHS(HocSinh hs[], int n){
	for(int i=0;i<n;i++){
		printf("\nHoc sinh thu %d\n", i+1);
		Nhap1HS(hs[i]);
	}
}
int SoSanhDate(Date a, Date b){
	if(a.ngay!=b.ngay) return 0;
	if(a.thang!=b.thang) return 0;
	if(a.nam!=b.nam) return 0;
	return 1;
}
int TimHocSinh(HocSinh hs[], int n, Date x){
	for(int i=0;i<n;i++)
		if(SoSanhDate(hs[i].NgaySinh, x))
			return i;
	return -1;
}
int main(){
	int n;
	printf("Nhap vao so luong hoc sinh: "); scanf("%d", &n);
	HocSinh hs[n];
	NhapDSHS(hs,n);
	Date x;
	printf("Nhap vao ngay sinh can tim (ngay/thang/nam): ");
	scanf("%d/%d/%d", &x.ngay, &x.thang, &x.nam);
	int kq= TimHocSinh(hs, n, x);
	if(kq!=-1){
		printf("\nHoc sinh co ngay sinh %d/%d/%d \n", x.ngay, x.thang, x.nam);
		printf("Ho ten: %s \t Ma hoc sinh: %d", hs[kq].ten, hs[kq].MS);
	}else
		printf("\nKhong tim thay hoc sinh co ngay sinh %d/%d/%d \n", x.ngay, x.thang, x.nam);
	return 0;
}
