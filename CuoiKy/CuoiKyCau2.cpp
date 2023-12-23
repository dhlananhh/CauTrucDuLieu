#include <stdio.h>
#include <string.h>

struct SINHVIEN  
{ 	char msv[10]; 
	char hoten[20]; 
	int gioitinh;  
	char ngaysinh[9]; 
	char diachi[50];  
};  
SINHVIEN dssv[40000];  

void swap(SINHVIEN &a, SINHVIEN &b){
	SINHVIEN temp = a;
	a= b;
	b = temp;
}
void sapXep(int left, int right){
	int i,j;
	SINHVIEN x;
	if(left < right){
		x = dssv[(left+ right)/2];
		i = left; j = right;
		do{
			while(strcmp(dssv[i].msv, x.msv) < 0) i++;
			while(strcmp(dssv[j].msv, x.msv) > 0) j--;
			if(i <= j){
				swap(dssv[i], dssv[j]);
				i++; j--;
			}
		}while(i < j);
		sapXep(left, j);
		sapXep(left, i);
	}	
}
SINHVIEN *timKiem(char key[], int left, int right){
	if(left > right) 
		return NULL;
	int mid = (left+right)/2;
	if(strcmp(key, dssv[mid].msv)==0)
		return &dssv[mid];
	if(strcmp(key, dssv[mid].msv) > 0)
		return timKiem(key, mid, right);
	return timKiem(key, left, mid);
}
int main(){
	
}

