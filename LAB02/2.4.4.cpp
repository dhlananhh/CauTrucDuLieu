#include<stdio.h>
#include<string.h>
struct EMPLOYEE 
{
	char name[30];
	long salary;
};
void Nhap(EMPLOYEE a[],int n){
	for(int i=0;i<n;i++){
		printf("\nNhap ten nhan vien thu %d: ",i+1);
		fflush(stdin);
		gets(a[i].name);
		printf("\nNhap luong cua nhan vien: ");
		scanf("%ld",&a[i].salary);
	}
}
void InsertionSort(EMPLOYEE a[],int n){
	int index;
	EMPLOYEE value; 
	for(int i=1;i<n;i++){
		index=i;
		value.salary=a[i].salary;
		while(index>0 && a[index-1].salary>value.salary){
			a[index]=a[index-1];
			index--;
		}
		a[i]=a[index];
	}
}
void Xuat(EMPLOYEE a[],int n){
	for(int i=0;i<n;i++){
		printf("\nTen nhan vien: ");
		puts(a[i].name);
		printf("\nLuong nhan vien la: %ld",a[i].salary);
	}
}
int main(){
	int n;
	printf("Nhap n: ");
	scanf("%d",&n);
	EMPLOYEE a[100];
	Nhap(a,n);
	InsertionSort(a,n);
	printf("\nNhan vien sau sap xep: ");
	Xuat(a,n);
	return 0;
}
