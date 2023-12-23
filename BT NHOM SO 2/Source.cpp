#include <iostream>
#include <string>

using namespace std;

struct Agency
{
	string name;
	double turnover;
	string phone;
	Agency* next;
};

struct City
{
	string name;
	Agency* down;
	City* next;	
};


Agency* CreateAgency(string aName, double aTur, string aPhone) {
	Agency* aNode = new Agency;
	aNode->name = aName;
	aNode->turnover = aTur;
	aNode->phone = aPhone;
	aNode->next = nullptr;
	
	return aNode;
}

City* CreateCity(string cName)
{
	City* cNode = new City;
	cNode->name = cName;
	cNode->next = nullptr;
	cNode->down = nullptr;
	return cNode;
}


City* AddCityHead(City* head, string cName) {
	City* temp = CreateCity(cName);
	if (head == NULL) {
		head = temp;
	}
	else {
		temp->next = head;
		head = temp;
	}
	return head;
}

City* AddCityTail(City* head, string cName) {
	City* temp, *p;
	temp = CreateCity(cName);
	if (head == NULL) {
		head = temp;
	}
	else {
		p = head;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = temp;
	}
	return head;
}

City* AddCityAt(City* head, string cName, int position) {
	if (position == 0 || head == NULL) {
		head = AddCityHead(head, cName);
	}
	else {
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

Agency* AddAgencyHead(Agency* head, string aName, double aTur, string aPhone) {
	Agency* temp = CreateAgency(aName,aTur,aPhone);
	if (head == NULL) {
		head = temp;
	}
	else {
		temp->next = head;
		head = temp;
	}
	return head;
}

Agency* AddAgencyTail(Agency* head, string aName, double aTur, string aPhone) {
	Agency* temp, * p;
	temp = CreateAgency(aName, aTur, aPhone);
	if (head == NULL) {
		head = temp;
	}
	else {
		p = head;
		while (p->next != NULL) {
			p = p->next;
		}
		p->next = temp;
	}
	return head;
}

Agency* AddAgencyAt(Agency* head, string aName, double aTur, string aPhone, int position) {
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

City* DelCityHead(City* head) {
	if (head == NULL) {
		return head;
	}
	else {
		head = head->next;
	}
	return head;
}

City* DelCityTail(City* head) {
	if (head == NULL || head->next == NULL) {
		return DelCityHead(head);
	}
	City* p = head;
	while (p->next->next != NULL) {
		p = p->next;
	}
	p->next = p->next->next;
	return head;
}

City* DelCityAt(City* head, int position) {
	if (position == 0 || head == NULL || head->next == NULL) {
		head = DelCityHead(head);
	}
	else {
		int k = 1;
		City* p = head;
		while (p->next->next != NULL && k != position) {
			p = p->next;
			++k;
		}

		if (k != position) {
			head = DelCityTail(head);
		}
		else {
			p->next = p->next->next;
		}
	}
	return head;
}

Agency* DelAgencyHead(Agency* head) {
	if (head == NULL) {
		return head;
	}
	else {
		head = head->next;
	}
	return head;
}

Agency* DelAgencyTail(Agency* head) {
	if (head == NULL || head->next == NULL) {
		return DelAgencyHead(head);
	}
	Agency* p = head;
	while (p->next->next != NULL) {
		p = p->next;
	}
	p->next = p->next->next;
	return head;
}

Agency* DelAgencyAt(Agency* head, int position) {
	if (position == 0 || head == NULL || head->next == NULL) {
		head = DelAgencyHead(head);
	}
	else {
		int k = 1;
		Agency* p = head;
		while (p->next->next != NULL && k != position) {
			p = p->next;
			++k;
		}

		if (k != position) {
			head = DelAgencyTail(head);
		}
		else {
			p->next = p->next->next;
		}
	}
	return head;
}

City* AddCity(City* head, string cName) {
	City* temp = CreateCity(cName);

	if (head == nullptr) {
		head = AddCityHead(head, cName);

		return head;
	}

	City* p = head;

	if (p->name >= cName) {
		head = AddCityHead(head, cName);

		return head;
	}

	while (p->next != nullptr)
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

Agency* AddAgency(Agency* head, string aName, double aTur, string aPhone) {
	Agency* temp = CreateAgency(aName, aTur, aPhone);

	if (head == nullptr) {
		head = AddAgencyHead(head, aName, aTur, aPhone);

		return head;
	}

	Agency* p = head;

	if (p->turnover >= aTur) {
		head = AddAgencyHead(head, aName, aTur, aPhone);

		return head;
	}

	while (p->next != nullptr)
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

int SearchCity(City* head, string value) {
	int position = 0;
	for (City* p = head; p != NULL; p = p->next) {
		if (p->name == value) {
			return position;
		}
		++position;
	}
	return -1;
}

Agency* SearchAgency(Agency* head, string value) {
	for (Agency* p = head; p != nullptr; p = p->next)
	{
		if (p->name == value)
			return p;
	}

	return nullptr;
}

City* addAgencyToCity(City* city, string cName, string aName, double aTur, string aPhone) {
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

Agency* SearchAgencyWithCity(City* city, string cName, string aName) {
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
	for (City* p = head; p != nullptr; p = p->next)
	{
		cout << p->name << "\t";
	}
}

void printCityWithAgency(City* head) {
	for (City* p = head; p != nullptr; p = p->next)
	{
		cout << p->name << ":\t";
		for (Agency* a = p->down; a != nullptr; a = a->next)
		{
			cout << "(" << a->name << ", " << a->turnover << ", " << a->phone << ")\t";
		}
		cout << endl;
	}
}

int findAgencyIndex(Agency* head, string value) {
	int position = 0;
	for (Agency* p = head; p != NULL; p = p->next) {
		if (p->name == value) {
			return position;
		}
		++position;
	}
	return -1;
}

City* delAgency(City* lCity, string cName, string aName) {
	int pos = SearchCity(lCity, cName);

	City* head = lCity;

	City* tCity = lCity;

	int k = 1;

	while (k != pos + 1) {
		tCity = tCity->next;
		k += 1;
	}

	Agency* tAgen = tCity->down;

	int aIndex = findAgencyIndex(tAgen, aName);

	tAgen = DelAgencyAt(tAgen, aIndex);

	tCity->down = tAgen;

	return head;
}

void printAgency(Agency* agency) {
	cout << "Name: " << agency->name << endl;
	cout << "Turnover: " << agency->turnover << endl;
	cout << "Phone: " << agency->phone << endl;
}

void menu(City* lCity) {
	do
	{
		cout << "\n\n\n";
		cout << "\t\t\t1. Print cities" << endl;
		cout << "\t\t\t2. Print cities and agencies" << endl;
		cout << "\t\t\t3. Search Agency with city's name" << endl;
		cout << "\t\t\t4. Delete Agency with city's name" << endl;
		cout << "\t\t\t5. Add Agency with city's name" << endl;
		cout << "\t\t\t6. Exit" << endl;
		cout << "\t\t\tChoose option: ";

		int choose;
		cin >> choose;

		if (choose == 6) {
			return;
		}

		cout << "\n\n\n";

		switch (choose)
		{
		case 1: {
			printCity(lCity);
			break;
		}
		case 2: {
			printCityWithAgency(lCity);
			break;
		}
		case 3: {
			string cName, aName;

			cout << "City's name: ";
			cin >> cName;

			cout << "Agency's name: ";
			cin >> aName;

			cout << "\n\n";

			Agency* agen = SearchAgencyWithCity(lCity, cName, aName);

			printAgency(agen);
			
			break;
		}
		case 4: {
			string cName, aName;

			cout << "City's name: ";
			cin >> cName;

			cout << "Agency's name: ";
			cin >> aName;

			cout << "\n\n";

			lCity = delAgency(lCity, cName, aName);

			break;
		}
		case 5: {
			string cName, aName, aPhone;
			double aTur;

			cout << "City's name: ";
			cin >> cName;

			cout << "Agency's name: ";
			cin >> aName;

			cout << "Agency's turnover: ";
			cin >> aTur;

			cout << "Agency's phone: ";
			cin >> aPhone;

			cout << "\n\n";

			lCity = addAgencyToCity(lCity, cName, aName, aTur, aPhone);

			break;
		}
		default:
			return;
		}
	} while (true);
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