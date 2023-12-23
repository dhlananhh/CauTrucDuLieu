#include<stdio.h>
#include<string.h>
struct NAME{
	char ten[30];
};
void Nhap(NAME a[],int n){
	for(int i=0;i<n;i++){
		printf("\nNhap ten thu %d: ",i+1);
		fflush(stdin);
		gets(a[i].ten);
	} 
}
void Xuat(NAME a[],int n){
	for(int i=0;i<n;i++){
		puts(a[i].ten);
		printf("\n");
	}
}
void Swap(NAME &a,NAME &b){
	NAME temp;
	temp=a;
	a=b;
	b=temp;
}
void BubbleSort(NAME a[],int n){
	for(int i=0;i<n;i++)
		for(int j=n-1;j>i;j--)
			if(strcmp(a[j].ten,a[j-1].ten)>0)
				Swap(a[j],a[j-1]);
			
}
int main(){
	int n;
	NAME ten[100];
	printf("Nhap so ten: ");
	scanf("%d",&n);
	Nhap(ten,n);
	BubbleSort(ten,n);
	printf("\nCac ten sau khi sap xep la:\n");
	Xuat(ten,n);
	return 0;
}
