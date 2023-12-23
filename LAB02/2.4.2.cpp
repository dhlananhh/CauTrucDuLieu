#include<stdio.h>
void Nhap(int a[],int n){
	for(int i=0;i<n;i++){
		printf("\nNhap so nguyen thu %d: ",i+1);
		scanf("%d",&a[i]);
	}
}
void Xuat(int a[],int n){ 
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
}
void InsertionSort(EMPLOYEE a[],int n){
	EMPLOYEE value; 
	int pos;
	for(int i=1;i<n;i++){
		pos=i; 
		value.salary=a[i].salary;
		while(pos>0 && a[pos-1].salary<value.salary){
			a[pos]=a[pos-1];
			pos--;
		}
		a[pos]=value;
	}
}
int main(){
	int a[100],n;
	printf("Nhap n: ");
	scanf("%d",&n);
	Nhap(a,n);
	InsertionSort(a,n);
	Xuat(a,n);
	return 0;
}
