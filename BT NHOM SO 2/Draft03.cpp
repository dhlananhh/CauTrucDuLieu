#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>


struct Agency {
	char name[50];
	double turnover;
	char phone[20];
	Agency *next;
};


struct City {
	char name[50];
	Agency *down;
	City *next;
};


Agency* CreateAgency (char aName[], double aTur, char aPhone[]) {
	Agency *aNode = new Agency;
	
	if (aNode == NULL)
		return NULL;
	else {
		strcpy(aNode->name, aName);
		aNode->turnover = aTur;
		strcpy(aNode->phone, aPhone);
		aNode->next = NULL;
	}
	
	return aNode;
}


City* CreateCity(char cName[]) {
	City* cNode = new City;
	
	if (cNode == NULL)
		return NULL;
	else {
		strcpy(cNode->name, cName);
		cNode->next = NULL;
		cNode->down = NULL;
	}
	
	return cNode;
}


City* AddCityHead(City* head, char cName[]) {
	City* temp = CreateCity(cName);
	if (head == NULL) {
		head = temp;
	} else {
		temp->next = head;
		head = temp;
	}
	return head;
}


City* AddCityTail(City* head, char cName[]) {
	City* temp, *p;
	temp = CreateCity(cName);
	if (head == NULL) {
		head = temp;
	} else {
		p = head;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = temp;
	}
	return head;
}


City* AddCityAt(City* head, char cName[], int position) {
	if (position == 0 || head == NULL) {
		head = AddCityHead(head, cName);
	} else {
		int k = 1;
		City* p = head;
		while (p != NULL && k != position) {
			p = p->next;
			++k;
		}

		if (k != position) {
			head = AddCityTail(head, cName);
		}
		else {
			City* temp = CreateCity(cName);
			temp->next = p->next;
			p->next = temp;
		}
	}
	return head;
}


Agency* AddAgencyHead(Agency* head, char aName[], double aTur, char aPhone[]) {
	Agency* temp = CreateAgency(aName,aTur,aPhone);
	if (head == NULL) {
		head = temp;
	} else {
		temp->next = head;
		head = temp;
	}
	return head;
}


Agency* AddAgencyTail(Agency* head, char aName[], double aTur, char aPhone[]) {
	Agency* temp, *p;
	temp = CreateAgency(aName, aTur, aPhone);
	if (head == NULL) {
		head = temp;
	} else {
		p = head;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = temp;
	}
	return head;
}


Agency* AddAgencyAt(Agency* head, char aName[], double aTur, char aPhone[], int position) {
	if (position == 0 || head == NULL) {
		head = AddAgencyHead(head, aName, aTur, aPhone);
	}
	else {
		int k = 1;
		Agency* p = head;
		while (p != NULL && k != position) {
			p = p->next;
			++k;
		}

		if (k != position) {
			head = AddAgencyTail(head, aName, aTur, aPhone);
		}
		else {
			Agency* temp = CreateAgency(aName,aTur,aPhone);
			temp->next = p->next;
			p->next = temp;
		}
	}
	return head;
}


City* AddCity(City* head, char cName[]) {
	City* temp = CreateCity(cName);

	if (head == NULL) {
		head = AddCityHead(head, cName);

		return head;
	}

	City* p = head;

	if (p->name >= cName) {
		head = AddCityHead(head, cName);

		return head;
	}

	while (p->next != NULL)
	{
		if (p->name <= cName && p->next->name >= cName) {
			temp->next = p->next;
			p->next = temp;
			return head;
		}
		else
		{
			p = p->next;
		}
	}

	head = AddCityTail(head, cName);

	return head;
}


Agency* AddAgency(Agency* head, char aName[], double aTur, char aPhone[]) {
	Agency* temp = CreateAgency(aName, aTur, aPhone);

	if (head == NULL) {
		head = AddAgencyHead(head, aName, aTur, aPhone);

		return head;
	}

	Agency* p = head;

	if (p->turnover >= aTur) {
		head = AddAgencyHead(head, aName, aTur, aPhone);

		return head;
	}

	while (p->next != NULL)
	{
		if (p->turnover <= aTur && p->next->turnover >= aTur) {
			temp->next = p->next;
			p->next = temp;
			return head;
		}
		else
		{
			p = p->next;
		}
	}

	head = AddAgencyTail(head, aName, aTur, aPhone);

	return head;
}


int SearchCity(City* head, char value[]) {
	int position = 0;
	for (City* p = head; p != NULL; p = p->next) {
		if (p->name == value) {
			return position;
		}
		++position;
	}
	return -1;
}

Agency* SearchAgency(Agency* head, char value[]) {
	for (Agency* p = head; p != NULL; p = p->next) {
		if (p->name == value)
			return p;
	}

	return NULL;
}


City* addAgencyToCity(City* city, char cName[], char aName[], double aTur, char aPhone[]) {
	int pos = SearchCity(city, cName);

	City* head = city;
	City* tCity = city;

	int k = 1;

	while (k != pos + 1) {
		tCity = tCity->next;
		k += 1;
	}

	Agency* tAgen = tCity->down;

	tAgen = AddAgency(tAgen,aName, aTur, aPhone);

	tCity->down = tAgen;

	return head;
}


Agency* SearchAgencyWithCity(City* city, char cName[], char aName[]) {
	int pos = SearchCity(city, cName);

	City* tCity = city;

	int k = 1;

	while (k != pos + 1) {
		tCity = tCity->next;
		k += 1;
	}

	Agency* tAgen = tCity->down;

	return SearchAgency(tAgen, aName);
}


void printCity(City* head) {
	for (City* p = head; p != nullptr; p = p->next)	{
		puts(p->name);
	}
}


void printAgency(Agency* agency) {
//	cout << "Name: " << agency->name << endl;
//	cout << "Turnover: " << agency->turnover << endl;
//	cout << "Phone: " << agency->phone << endl;

	printf("\nName: ");
	puts(agency->name);
	
	printf("\nTurnover: ");
	printf("%.2lf", agency->turnover);
	
	printf("\nPhone: ");
	puts(agency->phone);
}


void printCityWithAgency(City* head) {
	for (City* p = head; p != NULL; p = p->next) {
		puts(p->name);
		
		for (Agency* a = p->down; a != NULL; a = a->next) {
//			cout << "(" << a->name << ", " << a->turnover << ", " << a->phone << ")\t";
			puts(a->name);
			printf("%.2lf", a->turnover);
			puts(a->phone);
		}
	}
}


int menu (City *lCity) {
	bool flag = true;
	int c;
	char cName[50];
	char aName[50];
	char aPhone[20];
	double aTur;
	
	do {
		printf("\n1. Print cities\n");
		printf("\n2. Print cities and agencies");
		printf("\n3. Search Agency with city's name");
		printf("\n4. Delete Agency with city's name");
		printf("\n5. Add Agency with city's name");
		printf("\n6. Exit");
		
		printf("\nChoose option: ");
		scanf("%d", &c);
		
		switch (c) {
			case 1:
				printCity(lCity);
				break;
				
			case 2:
				printCityWithAgency(lCity);
				break;
			
			case 3:
				printf("\nCity's name: ");
				fflush(stdin);
				gets(cName);
				
				printf("Agency's name: ");
				fflush(stdin);
				gets(aName);
				
				Agency* agen = SearchAgencyWithCity(lCity, cName, aName);
				printAgency(agen);
				break;
/*				
			case 4:
				printf("\nCity's name: ");
				fflush(stdin);
				gets(cName);
				
				printf("Agency's name: ");
				fflush(stdin);
				gets(aName);
				
				lCity = delAgency(lCity, cName, aName);
				break;
*/

/*				
			case 5:
				printf("\nCity's name: ");
				fflush(stdin);
				gets(cName);
				
				printf("Agency's name: ");
				fflush(stdin);
				gets(aName);
				
				printf("Agency's turnover: ");
				scanf("%lf", &aTur);
				
				printf("Agency's phone: ");
				fflush(stdin);
				gets(aPhone);
				
				lCity = addAgencyToCity(lCity, cName, aName, aTur, aPhone);
				break;
*/				
//			case 6:
//				flag = false;
//				break;
		}
	} while (flag);
	
	return 0;
}


int main() {
	City* lCity = CreateCity("HN");

	lCity = AddCity(lCity, "AG");

	lCity = AddCity(lCity, "HCM");
	
	addAgencyToCity(lCity, "HCM", "MoMo", 100, "09123456798");
	addAgencyToCity(lCity, "HCM", "MaMa", 250.5, "0912345218");
	addAgencyToCity(lCity, "HCM", "BaBa", 250, "0912345218");

	addAgencyToCity(lCity, "HN", "MoMo", 500, "09123456798");
	addAgencyToCity(lCity, "HN", "MaMa", 240.5, "0912345218");
	addAgencyToCity(lCity, "HN", "BaBa", 249, "0912345218");

	addAgencyToCity(lCity, "AG", "MoMo", 500, "09123456798");
	addAgencyToCity(lCity, "AG", "MaMa", 250.5, "0912345218");
	addAgencyToCity(lCity, "AG", "BaBa", 900, "0912345218");	
	
	menu(lCity);
	
	return 0;
}