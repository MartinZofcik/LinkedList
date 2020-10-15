/*
Meno a priezvisko: Martin Žofèík 98034

POKYNY:
(1)  Subor premenujte na Priezvisko_Meno_ID_du02.cpp (pouzite vase udaje bez diakritiky).
(2)  Implementujte funkcie tak, aby splnali popis pri ich deklaraciach.
(3)  Cela implementacia musi byt v tomto jednom subore.
(4)  Odovzdajte len tento (spravne premenovany) zdrojovy subor.
(5)  Program musi byt kompilovatelny.
(6)  Globalne a staticke premenne su zakazane.
(7)  V ziadnom pripade nemente deklaracie funkcii, ktore mate za ulohu naprogramovat
	 (nemente nazvy, navratove hodnoty ani typ a pocet parametrov v zadanych funkciach).
	 Nemente implementacie hotovych pomocnych funkcii, ani implementacie zadanych datovych typov.
(8)  V pripade potreby mozete kod doplnit o dalsie pomocne funkcie alebo struktury.
(9)  Vase riesenie otestujte (vo funkcii 'main' a pomocou doplnenych pomocnych funkcii alebo struktur).
	 Testovaci kod ale nebude hodnoteny.
(10) Funkcia 'main' musi byt v zdrojovom kode posledna.
*/

#include <iostream>

using namespace std;

//-------------------------------------------------------------------------------------------------
// DATOVE TYPY
//-------------------------------------------------------------------------------------------------

// Reprezentacia uzla zretazeneho zoznamu
struct Node {
	int data; // hodnota uzla
	Node* next; // adresa nasledujuceho uzla zoznamu
};

// Reprezentacia zretazeneho zoznamu
struct List {
	Node* first; // adresa prveho uzla zoznamu
};

// Uspesnost vykonania funkcie
enum class Result {
	SUCCESS, // funkcia vykonana uspesne
	FAILURE  // chyba pri vykonavani funkcie
};

Node* createNode(const int val) {
	Node* newNode = new Node;
	newNode->data = val;
	newNode->next = nullptr;
	return newNode;
}

void printList(List* list) {
	Node* tmp = list->first;
	while (tmp) {
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << endl;
}


//-------------------------------------------------------------------------------------------------
// ULOHA c.1 (0.1 boda) Funkcia prida novy uzol s hodnotou 'val' na zaciatok zoznamu 'list'.
//-------------------------------------------------------------------------------------------------
void prependNode(List* list, const int val) {
	Node* newNode = createNode(val);
	newNode->next = list->first;
	list->first = newNode;
}

//-------------------------------------------------------------------------------------------------
// ULOHA c.2 (0.1 boda)	Funkcia prida novy uzol s hodnotou 'val' na koniec zoznamu 'list'.
//-------------------------------------------------------------------------------------------------
void appendNode(List* list, const int val) {
	Node* newNode = createNode(val);
	if (!list->first) {
		list->first = newNode;
	}
	else {
		Node* tmp = list->first;
		while (tmp->next) {
			tmp = tmp->next;
		}
		tmp->next = newNode;
		newNode->next = nullptr;
	}
}

//-------------------------------------------------------------------------------------------------
// ULOHA c.3 (0.1 boda)	Funkcia vytvori novy zretazeny zoznam a vyplni ho vsetkymi cislami (v zachovanom poradi),ktore sa nachadzaju vo vstupnom poli 'data', ktore ma dlzku 'n'.
//-------------------------------------------------------------------------------------------------
List* createListFromArray(const int* data, const int n) {
	List* list = new List;

	if (n < 0)
		return nullptr;
	if (n == 0) {
		list->first = nullptr;
		return list;
	}
	if (n > 0) {
		Node* newNode = createNode(data[0]);
		list->first = newNode;
		for (int i = 1; i < n; i++)
			appendNode(list, data[i]);
		//printList(list);
		return list;
	}
}

//-------------------------------------------------------------------------------------------------
// ULOHA c.4 (0.1 boda)  Funkcia vytvori novy symetricky zretazeny zoznam (vid priklady) podla parametra 'val'. Symetricky zoznam ma	tvar 0,1,2,...val...2,1,0.
//-------------------------------------------------------------------------------------------------
List* createSymmetricList(const int val) {
	List* list = new List;
	Node* newNode = createNode(0);

	list->first = newNode;
	for (int i = 1; i <= val; i++) 
		appendNode(list, i);
	for (int j = val - 1; j >= 0; j--) 
		appendNode(list, j);
	return list;
}

//-------------------------------------------------------------------------------------------------
// ULOHA c.5 (0.1 boda) Funkcia odstrani (aj spravne uvolni pamat) zo vstupneho zoznamu 'list' prvy uzol.
//-------------------------------------------------------------------------------------------------
Result removeFirstNode(List* list) {
	if (list->first) {
		Node* tmp = list->first->next;
		delete list->first;
		list->first = tmp;
		return Result::SUCCESS;
	}
	else
		return Result::FAILURE;
}

//-------------------------------------------------------------------------------------------------
// ULOHA c.6 (0.1 boda) Funkcia najde prvy uzol zretazeneho zoznamu 'list', ktory obsahuje hodnotu 'val'.
//-------------------------------------------------------------------------------------------------
Node* findNodeInList(List* list, const int val) {
	Node* tmp = list->first;
	while (tmp) {
		if (tmp->data == val) {
			return tmp;
		}
		tmp = tmp->next;
	}
	return nullptr;
}

//-------------------------------------------------------------------------------------------------
// ULOHA c.7 (0.1 boda)
//-------------------------------------------------------------------------------------------------
/*
	Funkcia zisti, ci su dva vstupne zoznamy 'list1' a 'list2' rovnake (t.j. rovnako dlhe a obsahujuce
	rovnake hodnoty uzlov v rovnakom poradi).

	PARAMETRE:
		[in] list1 - prvy zretazeny zoznam
		[in] list2 - druhy zretazeny zoznam

	RETURN:
		'true' - ak su vstupne zoznamy rovnake
		'false' - ak vstupne zoznamy nie su rovnake

	PRIKLADY:
		list1={1}
		list2={}
		Funkcia vrati 'false'.

		list1={}
		list2={5,3}
		Funkcia vrati 'false'.

		list1={}
		list2={}
		Funkcia vrati 'true'.

		list1={1}
		list2={1}
		Funkcia vrati 'true'.

		list1={4,-9,2}
		list2={4,-9,2}
		Funkcia vrati 'true'.

		list1={3,2,1}
		list2={1,2,3}
		Funkcia vrati 'false'.

		list1={2}
		list2={7,4,5}
		Funkcia vrati 'false'.
*/

bool areListsEqual(List* list1, List* list2) {
	return true; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}


//-------------------------------------------------------------------------------------------------
// ULOHA c.8 (0.1 boda)
//-------------------------------------------------------------------------------------------------
/*
	Funkcia vytvori novy zretazeny zoznam prekopirovanim vsetkych hodnot uzlov vstupneho zoznamu 'list' v obratenom
	poradi.

	PARAMETRE:
		[in] list - vstupny zretazeny zoznam

	RETURN:
		Zretazeny oznam, ktory vznikne prekopirovanim hodnot uzlov vstupneho zoznamu 'list' v obratenom poradi.

	PRIKLADY:
		list={} ... funkcia vrati ... {} t.j. prazdny zoznam
		list={1} ... funkcia vrati ... {1}
		list={5,6} ... funkcia vrati ... {6,5}
		list={8,14,2,3} ... funkcia vrati ... {3,2,14,8}
*/

List* copyListReverse(List* list) {
	// TODO
	return nullptr; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// ULOHA c.9 (0.1 boda)
//-------------------------------------------------------------------------------------------------
/*
	Funkcia vyhlada predchodcu zadaneho uzla 'node' vo vstupnom zretazenom zozname 'list'. Uzol 'node' je vzdy
	existujucim uzlom vstupneho zoznamu 'list'.

	PARAMETRE:
		[in] list - vstupny zretazeny zoznam
		[in] node - uzol zretazeneho zoznamu 'list', ktoreho predchodcu hladame

	RETURN:
		Uzol, ktory je predchodcom uzla 'node' v zozname 'list'. V pripade hladania predchodcu prveho uzla zoznamu,
		funkcia vrati 'nullptr'.

	PRIKLADY:
		list={4}
		node=4
		Funkcia vrati 'nullptr'.

		list={1,2,3,4,5}
		node=1
		Funkcia vrati 'nullptr'.

		list={-2,-3,56,4,41}
		node=-3
		Funkcia vrati uzol s hodnotou -2.

		list={10,54,69,82,6}
		node=6
		Funkcia vrati uzol s hodnotou 82.
*/

Node* findPreviousNode(List* list, Node* node) {
	// TODO
	return nullptr; // tento riadok zmente podla zadania, je tu len kvoli kompilacii
}

//-------------------------------------------------------------------------------------------------
// ULOHA c.10 (0.1 boda)
//-------------------------------------------------------------------------------------------------
/*
	Funkcia zduplikuje vsetky uzly vstupneho zoznamu 'list', ktore obsahuju kladnu hodnotu.

	PARAMETRE:
		[in,out] list - vstupny zretazeny zoznam

	PRIKLADY:
		list={} ... po vykonani funkcie ... {}
		list={3} ... po vykonani funkcie ... {3,3}
		list={-1,1} ... po vykonani funkcie ... {-1,1,1}
		list={-8,-9,-13} ... po vykonani funkcie ... {-8,-9,-13}
		list={1,0,-2,3,-4} ... po vykonani funkcie ... {1,1,0,-2,3,3,-4}
*/

void duplicatePositiveNodes(List* list) {

}



//-------------------------------------------------------------------------------------------------
// TESTOVANIE
//-------------------------------------------------------------------------------------------------

// tu mozete doplnit pomocne funkcie a struktury

int main(int argc, char** argv) {
		List* list;

	//int data[5] = { 1,2,3,4,5 };
	//printList(createListFromArray(data, 5));

	//printList(createSymmetricList(10));

	//int data[5] = { 1,2,3,4,5 };
	//list = createListFromArray(data, 5);
	//removeFirstNode(list);
	//printList(list);

	//int data[5] = { 1,2,3,4,5 };
	//list = createListFromArray(data, 5);
	//cout << findNodeInList(list, 5);

	//int data[5] = { 1,2,3,4,5 };
	//list = createListFromArray(data, 5);
	//duplicatePositiveNodes(list);

	return 0;
}
