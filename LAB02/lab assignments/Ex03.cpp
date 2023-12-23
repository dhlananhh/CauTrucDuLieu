#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define max 100


int main() {
	
}


void randName (char name[], int k) {
	for (int i=0; i<k; i++) {
		if (i==0)
			name[i] = 65+rand()%25;
		else
			name[i] = 97+rand()%25;
	}
	name[k] = 0;
}

