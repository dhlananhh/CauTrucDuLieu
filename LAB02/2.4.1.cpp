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
void Swap(int &a,int &b){
	int temp;
	temp=a;
	a=b;
	b=temp;
}
void BubbleSort(int a[],int n){
	for(int i=0;i<n;i++)
		for(int j=n-1;j>i;j--)
			if(a[j]>a[j-1])
				Swap(a[j],a[j-1]);
}
int main(){
	int a[100],n;
	printf("Nhap n: ");
	scanf("%d",&n);
	Nhap(a,n);
	BubbleSort(a,n);
	printf("\nDay sau khi sap xep: ");
	Xuat(a,n);
	return 0;
}
