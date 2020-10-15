#include "linkedlist.cpp"

//// funkcia na vytvorenie noveho uzla
Node* createNode(const int val) {
	Node* newNode = new Node;
	newNode->data = val;
	newNode->next = nullptr;
	return newNode;
}
//
//// funkcia na vypis zoznamu
void printList(List* list) {
	Node* tmp = list->first;
	while (tmp) {
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << endl;
}
//
//// funkcia na pridanie uzla na zaciatok zoznamu
void prependNode(List* list, const int val) {
	Node* newNode = createNode(val);
	newNode->next = list->first;
	list->first = newNode;
}
//
//// funkcia na pridanie uzla na koniec zoznamu
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
	}
}

// funkcia na vyhladanie uzla v zozname
Node* findNode(List* list, const int val) {
	Node* tmp = list->first;
	while (tmp) {
		if (tmp->data == val) {
			break;
		}
		tmp = tmp->next;
	}
	return tmp;
}

// funkcia na vymazanie prveho uzla zoznamu
void removeFirstNode(List* list) {
	if (list->first) {
		Node* tmp = list->first->next;
		delete list->first;
		list->first = tmp;
	}
}

// funkcia na vymazanie posledneho uzla zoznamu
void removeLastNode(List* list) {
	if (list->first) {
		Node* tmp = list->first;
		Node* prev = nullptr;
		while (tmp->next) { // vyhladanie posledneho uzla
			prev = tmp;
			tmp = tmp->next;
		}
		if (!prev) { // 1-prvkovy zoznam
			list->first = nullptr;
		}
		else { // viac-prvkovy zoznam
			prev->next = nullptr;
		}
		delete tmp; // dealokacia posledneho uzla
	}
}

// funkcia, ktora vymaze (dealokuje) vsetky uzly zoznamu (zoznam bude existovat v pamati, ale bude prazdny)
void clearList(List* list) {
	Node* tmp = nullptr;
	while (list->first) {
		tmp = list->first->next;
		delete list->first;
		list->first = tmp;
	}
}

// funkcia na vymazanie (dealokaciu) celeho zoznamu z pamate
// Vysvetlujuca poznamka:
// ... ak chcem vo funkcii 'destroyList' zmodifikovat premennu typu List ---> parameter musi byt typu List*
// ... ak chcem vo funkcii 'destroyList' zmodifikovat premennu typu List* ---> parameter musi byt typu List**
void  destroyList(List** list) {
	clearList(*list); // vymazanie vsetkych uzlov zoznamu, avsak pamat pre strukturu so zoznamom zostavana alokovana
	delete (*list); // dealokacia pamate pre strukturu so zoznamom
	(*list) = nullptr;
}

int main()
{
	 1. vytvorenie noveho prazdneho zoznamu .........................................................
	List* list = new List; // dynamicka alokacia zoznamu
	list->first = nullptr; // smernik na prvy uzol obsahuje 'nullptr', t.j. neukazuje na ziadny uzol

	 //2. pridanie uzlov na zaciatok zoznamu .........................................................
	int num = 5;
	for (int i = 0; i < num; i++) {
		prependNode(list, i);
	}
	cout << "Pridavanie na zaciatok:" << endl;
	printList(list);

	// 3. pridanie uzlov na koniec zoznamu .........................................................
	for (int i = 0; i < num; i++) {
		appendNode(list, i);
	}
	cout << "Pridavanie na koniec:" << endl;
	printList(list);

	//// 4. vyhladanie uzlov v zozname ...............................................................
	//Node* result1 = findNode(list, 0); // otestujte si v Debug rezime
	//Node* result2 = findNode(list, 100); // otestujte si v Debug rezime

	//// 5. vymazanie prveho uzla zoznamu ............................................................
	//removeFirstNode(list);
	//cout << "Vymazanie prveho uzla:" << endl;
	//printList(list);

	//// 6. vymazanie posledneho uzla zoznamu ........................................................
	//removeLastNode(list);
	//cout << "Vymazanie posledneho uzla:" << endl;
	//printList(list);

	//// 7. vymazanie celeho zoznamu z pamate ........................................................
	//destroyList(&list); // otestujte si v Debug rezime

	return 0;
}
