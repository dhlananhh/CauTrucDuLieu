#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct DaiLy{
	char tenDL[30];
	double doanhThu;
	char sdt[12];
	DaiLy *tiep;
};
struct ThanhPho{
	char tenTP[30];
	DaiLy *down;
	ThanhPho *next;
};
ThanhPho *head=NULL;
ThanhPho* taoTP(char tenTP[]){
	ThanhPho* tp = new ThanhPho;
	if(tp==NULL){
		printf("\nBo nho day!");
		return NULL;
	}
	else{
		strcpy(tp->tenTP, tenTP);
		tp->down = NULL;
		tp->next = NULL;
	}
	return tp;		
}
void themTP(char tenTP[]){
	ThanhPho* tp = taoTP(tenTP);
	if(head==NULL)
		head=tp;
	else{
		if(strcmp(tp->tenTP, head->tenTP)<0){
			tp->next = head;
			head = tp;
		}
		else{
			ThanhPho *temp=head;
			while( temp->next!=NULL && strcmp(temp->next->tenTP,tp->tenTP)<0 )
				temp=temp->next;
			tp->next = temp->next;
			temp->next = tp;
		}
	}
	printf("Da them");
}
ThanhPho *timThanhPho(char tentp[]){
	for(ThanhPho* tp=head; tp!=NULL; tp=tp->next)
		if(strcmp(tp->tenTP, tentp)==0)
			return tp;
	return NULL;
}
DaiLy* nhapDaiLy(){
	DaiLy *dl = new DaiLy;
	if(dl==NULL){
		printf("Bo nho day!");
		return NULL;
	}
	else{
		printf("Nhap ten dai ly: "); fflush(stdin); gets(dl->tenDL);
		printf("Nhap doanh thu: "); scanf("%lf", &dl->doanhThu);
		printf("Nhap sdt: "); fflush(stdin); gets(dl->sdt);
		dl->tiep = NULL;
		return dl;
	}
}
void themDaiLyVaoThanhPho(char tentp[]){
	ThanhPho *tp = timThanhPho(tentp);
	if(tp == NULL)
		printf("\nKhong tim thay thanh pho");
	else{
		DaiLy* dl = nhapDaiLy();
		if(tp->down==NULL)
			tp->down= dl;
		else{
			if(dl->doanhThu < tp->down->doanhThu){
				dl->tiep = tp->down;
				tp->down = dl;
			}
			else{
				DaiLy *temp=tp->down;
				while( temp->tiep!=NULL && temp->tiep->doanhThu < dl->doanhThu)
					temp=temp->tiep;
				dl->tiep = temp->tiep;
				temp->tiep = dl;
			}	
		}
		printf("Da them");
	}
}
DaiLy *timDaiLy(char tendl[],char tentp[]){
	ThanhPho *tp = timThanhPho(tentp);
	for(DaiLy *dl= tp->down; dl!=NULL; dl= dl->tiep)
		if(strcmp(dl->tenDL, tendl)==0)
			return dl;
	return NULL;
}
void in1DaiLy(DaiLy *dl){
	printf("\nTen dai ly: %s", dl->tenDL);
	printf("\nDoanh thu: %.2lf", dl->doanhThu);
	printf("\nSdt: %s", dl->sdt);
}
void suaDaiLy(char tendl[], char tentp[]){
	DaiLy *dl = timDaiLy(tendl,tentp);
	if(dl==NULL)
		printf("\nKhong tim thay dai li");
	else{
		printf("Nhap ten dai ly moi: "); fflush(stdin); gets(dl->tenDL);
		printf("Nhap doanh thu moi: "); scanf("%lf", &dl->doanhThu);
		printf("Nhap sdt moi: "); fflush(stdin); gets(dl->sdt);
		printf("Da sua");
	}
}
bool xoaDaiLy(char tendl[], char tentp[]){
	DaiLy *dl = timDaiLy(tendl,tentp);
	if(dl==NULL)
		return false;
	ThanhPho *tp= timThanhPho(tentp);
	if(dl = tp->down){
		tp->down=tp->down->tiep;
		free(dl);
		return true;
	}
	DaiLy* pre=tp->down;
	while(pre->tiep != dl)
		pre=pre->tiep;
	pre=dl->tiep;
	free(dl);
	return true;
}
void inDSDLTrongTP(ThanhPho *tp){
	for(DaiLy *dl=tp->down; dl!=NULL; dl=dl->tiep)
		in1DaiLy(dl);
}
void inDSTP(){
	for(ThanhPho *tp=head; tp!=NULL; tp= tp->next){
		printf("\n%s", tp->tenTP);
		inDSDLTrongTP(tp);
	}
}
int main(){
	int c;
	do{
		printf("\n1. Them 1 thanh pho");
		printf("\n2. Them 1 dai ly vao 1 thanh pho");
		printf("\n3. Tim 1 dai ly");
		printf("\n4. Sua 1 dai ly");
		printf("\n5. Xoa 1 dai ly");
		printf("\n6. In tat ca dai ly");
		printf("\n0. Thoat");
		printf("\nNhap vao lua chon: "); scanf("%d", &c);
		char tentp[30], tendl[30];
		DaiLy *dl= new DaiLy;
		switch(c){
			case 1:
				printf("Nhap ten thanh pho: "); fflush(stdin); gets(tentp);
				themTP(tentp);
				break;
			case 2:
				printf("Nhap ten thanh pho: "); fflush(stdin); gets(tentp);
				themDaiLyVaoThanhPho(tentp);
				break;
			case 3:
				printf("Nhap vao ten thanh pho: "); fflush(stdin); gets(tentp);
				printf("Nhap vao ten dai ly: "); fflush(stdin); gets(tendl);
				dl = timDaiLy(tendl,tentp);
				if(dl==NULL)
					printf("Khong tim thay dai ly");
				else
					in1DaiLy(dl);
				break;
			case 4:
				printf("Nhap vao ten thanh pho: "); fflush(stdin); gets(tentp);
				printf("Nhap vao ten dai ly: "); fflush(stdin); gets(tendl);
				suaDaiLy(tendl,tentp);
				break;
			case 5:
				printf("Nhap vao ten thanh pho: "); fflush(stdin); gets(tentp);
				printf("Nhap vao ten dai ly: "); fflush(stdin); gets(tendl);
				if(xoaDaiLy(tendl,tentp))
					printf("Da xoa");
				else
					printf("Khong tim thay dai ly");
				break;
			case 6:
				for(ThanhPho* tp=head; tp!=NULL; tp=tp->next)
					inDSDLTrongTP(tp);
				break;
		}
	}while(c!=0);
	return 0;
}
