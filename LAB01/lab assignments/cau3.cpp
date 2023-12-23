#include<stdio.h>
struct date
{
	int dd, mm, yy;
};
struct record
{
	int roll;
	char name[20];
	date dob;	
};

void nhapDSSV(record s[], int n)
{
	for(int i=0; i<n; i++)
	{
		printf("Nhap ma:");
		scanf("%d", &s[i].roll);
		fflush(stdin);
		printf("Ten:");
		gets(s[i].name);
		printf("Nhap ngay/thang/nam sinh:");
		scanf("%d/%d/%d", &s[i].dob.dd, &s[i].dob.mm,&s[i].dob.yy);
	}
}
int timTheoMa(record s[], int n, int key)
{
	
}
int timTheoTen(record s[], int n, char tenTim[])
{
	//if(strcmp(s[i].name, tenTim)==0)
}
void timTheoNgaySinh(record s[], int n, date x)
{
	...
	if(s[i].dob.dd==x.dd && s[i].dob.mm==x.mm && s[i].dob.yy==x.yy )
		xuat1SV(s[i]);
}
int main()
{
	record s[100];
	
	scanf("%d", &s[i].roll);
	gets(s[i].name);
	
	//nhap ngay/thang/nam
	scanf("%d/%d/%d", &s[i].dob.dd, &s[i].dob.mm,..)
	
}
