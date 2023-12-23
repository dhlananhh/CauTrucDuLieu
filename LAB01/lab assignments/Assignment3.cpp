#include<bits/stdc++.h>

struct Record
{
	int RollNo;
	char Name[20];
	struct Date{int dd; int mm; int yy;} dob;
};

void nhap1Record(Record &hs);
void nhapdsRecord(Record dshs[]);
void xuatdsRecord(Record dshs[]);
void xuat1Record(Record dshs[], int i);
void randTen(char ten[],int m);
int searchLinear(Record arr[],int x, int y, int z, int a[]);

int main()
{
	Record students[100];
	nhapdsRecord(students);
	xuatdsRecord(students);
	int m,d,y;
	printf("\nEnter the search element: ");
	scanf("%2d/%2d/%2d",&d,&m,&y);
	int a[100];
	
	int kt=searchLinear(students,d,m,y,a);
	if(kt==-1)
		printf("\nElement not found");
	else
	{
		printf("\nThe element found at %d position: ",kt+1);
		for(int i=0; i<kt+1; i++)
			printf("%d\t",a[kt]);
		printf("\n%-4s|%-6s|%-10s|%-20s","STT","Maso","Ten","Ngay thang nam sinh");
		for	(int i=0; i<kt+1; i++)
			xuat1Record(students,a[i]);	
	}
	
	
}

void nhap1Record(Record &hs)
{
	
	hs.RollNo =rand() % 1000;
//	gets(hs.Name);
	randTen(hs.Name,2 + rand()%5);
	hs.dob.yy=rand() % (99);
	hs.dob.mm=1+rand() % (12);
	if(hs.dob.mm==1||hs.dob.mm==3||hs.dob.mm==5||hs.dob.mm==7||hs.dob.mm==8||hs.dob.mm==10||hs.dob.mm==12)
		hs.dob.dd=1+rand() % (31);
	else if(hs.dob.mm==4||hs.dob.mm==6||hs.dob.mm==9||hs.dob.mm==11)
		hs.dob.dd=1+rand() % (30);
	else
		hs.dob.dd=1+rand() % (28);
}

void randTen(char ten[],int m)
{
    for (int i=0; i<m; i++)
	{
		if(i==0)
			ten[i] = 65 + rand()%25;
		else
			ten[i] = 97 + rand()%25;
	} 
    ten[m] = 0;
}	

void nhapdsRecord(Record dshs[])
{
	srand ( (int)time (NULL));
	for(int i=0; i<100; i++)
	{
		nhap1Record(dshs[i]);
	}
}
void xuat1Record(Record dshs[], int i)
{
	printf("\n%-4d|%-6d|%-10s|%02d/%02d/%02d",i+1,dshs[i].RollNo,dshs[i].Name,dshs[i].dob.dd,dshs[i].dob.mm,dshs[i].dob.yy);
}
void xuatdsRecord(Record dshs[])
{
	printf("%-4s|%-6s|%-10s|%-20s","STT","Maso","Ten","Ngay thang nam sinh");
	for(int i=0; i<100; i++)
	{
		printf("\n%-4d|%-6d|%-10s|%02d/%02d/%02d",i+1,dshs[i].RollNo,dshs[i].Name,dshs[i].dob.dd,dshs[i].dob.mm,dshs[i].dob.yy);
	}
}

int searchLinear(Record arr[],int x, int y, int z,int a[])
{ 	
	int j=-1;
    for (int i = 0; i < 100; i++) 
        if (arr[i].dob.dd == x && arr[i].dob.mm == y && arr[i].dob.yy == z) 
        {
        	j++;
        	a[j]=i;
		}
	if(j==-1)
		return -1;	     
    else 
		return j; 

}

