#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<stdlib.h>

struct dl{
	char tendl[30];
	long doanhthu;
	char sdt[15];
};
struct nodedl{
	dl data;
	nodedl *tiep;
};
struct tp{
	char tentp[30];
};
struct nodetp{
	tp data;
	nodedl *down;
	nodetp *next;
};
struct Listdl{
	nodedl *head_dl;
	nodedl *tail_dl;
};
struct Listtp{
	nodetp *head_tp;
	nodetp *tail_tp; 
};

void CreateListdl(Listdl &l){
	l.head_dl=l.tail_dl=NULL;
}
void CreateListtp(Listtp &L){
	L.head_tp=L.tail_tp=NULL;
}
nodedl *CreateNodedl(dl x){
	nodedl *p=new nodedl;
	if(p==NULL)
		return NULL;
	p->data=x;
	p->tiep=NULL;
	return p;
}
nodetp *CreateNodetp(tp x){
	nodetp *p=new nodetp;
	if(p==NULL)
		return NULL;
	p->data=x;
	p->next=NULL;
	p->down=NULL;
	return p;
}
void xuat1dl(dl x){
	printf("\nTen dai ly: ");
	puts(x.tendl);
	printf("\nDoanh thu: %ld",x.doanhthu);
	printf("\nSo dien thoai: ");
	puts(x.sdt); 
}
void xuat1tp(nodetp *L){
	nodedl *p;
	p=L->down;
	while(p!=NULL){
		xuat1dl(p->data);
		p=p->tiep;
	}
}
void xuatds(Listtp L){
//	nodetp *p;
//	p=L.head_tp;
//	while(p!=NULL){
//		printf("\nTen thanh pho: ");
//		puts(p->data.tentp);
//		xuat1tp(p);
//		p=p->next;
//	}

	nodetp *b;
	for (nodedl *a = b->down; a != NULL; a = a->tiep)
		xuat1dl(a->data);
		
	for (nodetp *b = L.head_tp; b != NULL; b = b->next) {
		printf("\nTen thanh pho: ");
		puts(b->data.tentp);
		xuat1tp(b);
		b=b->next;
	}
}
/*
nodedl *taonode(dl x){
	nodedl *p=new nodedl;
	if(p==NULL){
		printf("\nKhong du bo nho !!!");
		return NULL;
	}
	p->data = x;
	return p; 
}
*/
nodedl *themdlcuoi (dl x, Listdl &l){
	nodedl *p=CreateNodedl(x);
	if(p==NULL)
		return NULL;
	if  (l.head_dl==NULL){
		l.head_dl =p;
		l.tail_dl = p;
	}
	else{  	
		l.tail_dl->tiep = p;	
		l.tail_dl = p; 		
	}
}
nodetp *themtpcuoi(tp x,Listtp &L,Listdl l){
	nodetp *p=CreateNodetp(x);
	if(p==NULL)
		return NULL;
	if  (L.head_tp==NULL){
		L.head_tp =p;
		L.tail_tp = p;
		L.tail_tp->down=l.head_dl;
	}
	else{  	
		L.tail_tp->next = p;
		L.tail_tp = p; 	
		L.tail_tp->down=l.head_dl;	
	}
}
void InterChangeSort(Listdl  &l)
{
	for(nodedl* p=l.head_dl;p!=l.tail_dl;p=p->tiep)
		for(nodedl* q=p->tiep;q!=NULL;q=q->tiep)
			if (p->data.doanhthu > q->data.doanhthu){
				nodedl *temp;
				temp->data=q->data;
				q->data=p->data;
				p->data=temp->data;
			}
} 

void nhap1dl(dl &x){
	printf("\nNhap ten dai ly: ");
	fflush(stdin);
	gets(x.tendl);
	printf("Nhap doanh thu: ");
	scanf("%ld",&x.doanhthu);
	printf("\nNhap so dien thoai: ");
	fflush(stdin);
	gets(x.sdt);
}
void nhap1tp(Listdl &l){
	int m;
	dl x; 
	printf("\nNhap so dai ly: ");
	scanf("%d",&m); 
	for(int i=0;i<m;i++){
		nhap1dl(x);
		themdlcuoi(x,l); 
	}  
}
void nhapds(int n, Listtp &L){
	tp x; 
	Listdl l;
	for(int i=0;i<n;i++){
		printf("\nNhap thanh pho thu %d",i+1);
		printf("\nNhap ten thanh pho: ");
		fflush(stdin);
		gets(x.tentp);
		CreateListdl(l); 
		nhap1tp(l);
		InterChangeSort(l);
		themtpcuoi(x,L,l);
	}
}
int main(){
	Listtp L;
	int n, chon;
	printf("\nNhap so thanh pho: ");
	scanf("%d",&n);
	nhapds(n,L);
	xuatds(L);
    return 0;
}