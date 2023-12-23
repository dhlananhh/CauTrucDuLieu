#include <stdio.h>

struct THONGTIN{   
	char maSV[10];   
	char hoSV[20];  
	char tenSV[30];  
 	float diemCK;  
 	char  lop[20];  
};  
struct NODE{   
 	THONGTIN data;  
 	NODE *link;  
}; 
struct LIST{  
 	NODE* first;  
 	NODE* last;    
};  
void taoDSLopY(char y[], LIST L, LIST &L1){
	for(NODE* p= L.first; p!=NULL; p=p->link)
		if(strcmp(y, p->data.lop)==0)
			ThemDau(L1, p->data);
}
void tachDS(char y[], LIST L, LIST &L1, LIST &L2){
	NODE *p;
	while(L.first!=NULL){
		p= L.first;		
		L.first = L.first->link;
		if(strcmp(y, p->data.maSV)==0)
			ThemDau(L1, p->data);
		else
			ThemDau(L2, p->data);
		free(p);
	}
}
void tronDS(LIST &L1, LIST &L2){
	NODE *p;
	while(L2.first!=NULL){
		p= L2.first;
		L2.first = L2.first->link;
		if(strcmp(p->data.maSV, L1.first->data.maSV) < 0)
			ThemDau(L1, p->data);
		else{
			NODE *q = L1.first;
			while(q->link!=NULL && strcmp(p->data.maSV, q->link->data.maSV) > 0)
				q= q->link;
			p->link = q->link;
			q->link = p;
		}
	}
}
int main(){
	
	
	return 0;
}

