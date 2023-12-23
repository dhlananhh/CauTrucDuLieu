#include<stdio.h>
#include<string.h>
struct Record{ 
	int RollNo;
	char name[20];
	struct Date { int dd; int mm; int yy; } dob;
};
void nhap(Record a[], int n){
	for(int i=0;i<n;i++){
		printf("Nhap RollNo: ");
		scanf("%d",&a[i].RollNo);
		printf("\nNhap ten: ");
		fflush(stdin);
		gets(a[i].name);
		printf("\nNhap ngay sinh: ");
		scanf("%d/%d/%d",&a[i].dob.dd,&a[i].dob.mm,&a[i].dob.yy);
	} 
}
void xuat(Record a){
	printf("\nRoll No: %d",a.RollNo);
	printf("\nTen hoc vien: ");
	puts(a.name);
	printf("\nNgay sinh hoc vien: %d/%d/%d",a.dob.dd,a.dob.mm,a.dob.yy);
}
int TimKiemDob(Record a[], int n, Record c){
	int x=-1;
	for(int i=0;i<n;i++)
		if(a[i].dob.dd==c.dob.dd && a[i].dob.mm==c.dob.mm && a[i].dob.yy==c.dob.yy){
			x=i;
			break;
		}
	return x;
}
int TimKiemTen(Record a[], int n,Record c ){
	int x=-1;
	for(int i=0;i<n;i++)
		if(strcmp(a[i].name,c.name)==0){
			x=i;
			break;
		}
	return x;
}
int TimKiemRollNo(Record a[], int n, Record c){
	int x=-1;
	for(int i=0;i<n;i++)
		if(a[i].RollNo==c.RollNo){
			x=i;
			break;
		}
	return x;
} 
int main(){
	int n,chon,b;
	Record students[100],c;
	printf("\nNhap so hoc vien can nhap: ");
	scanf("%d",&n);
	nhap(students,n);
	printf("\nChon phuong thuc tim kiem:");
	printf("\n1.Tim kiem bang RollNo");
	printf("\n2.Tim kiem bang ten");
	printf("\n3.Tim kiem bang ngay sinh\n");
	do{
		scanf("%d",&chon);
		switch (chon){
			case 1:
				printf("\nNhap RollNo cua sinh vien can tim: ");
				scanf("%d",&c.RollNo);
				b=TimKiemRollNo(students,n,c);
				if(b==-1)
					printf("\nNot found");
				else
					xuat(students[b]);
				break;
			case 2:
				printf("\nNhap ten cua sinh vien can tim: ");
				fflush(stdin);
				gets(c.name);
				b=TimKiemTen(students,n,c);
				if(b==-1)
					printf("\nNot found");
				else
					xuat(students[b]);
				break;
			case 3:
				printf("\nNhap ngay sinh cua sinh vien can tim: ");
				scanf("%d/%d/%d",&c.dob.dd,&c.dob.mm,&c.dob.yy);
				b=TimKiemDob(students,n,c);
				if(b==-1)
					printf("\nNot found");
				else
					xuat(students[b]);
				break;
			default:
				printf("\nNhap sai, vui long nhap lai: ");
		}
	}while (chon>3);
	return 0;
}
