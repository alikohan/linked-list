#include <iostream>
#include <stdlib.h>

using namespace std;
void PrintMenu();
void PrintBigMenu();


struct node {
	node* Next;
	int value;
};

class LinkedList {
public:
	node* start = NULL;
	int counter = 0;

public:
	LinkedList() {
		start = NULL;
	}
	void CreateList(int v) {
		node* n = new node;
		n->Next = NULL;
		n->value = v;
		start = n;
		counter++;
		cout << "successfully created!" << endl;
	}
	void InsertAtStart(int v) {
		node* n = new node;
		n->Next = start;
		n->value = v;
		start = n;
		counter++;
		cout << "successfully inserted!" << endl;
	}

	void InsertAtEnd(int v, bool forPrint) {
		if (!start) {
			CreateList(v);
			return;
		}
		node* n = new node;
		node* carry = start;
		for (; carry->Next != NULL; carry = carry->Next);
		n->value = v;
		n->Next = NULL;
		carry->Next = n;
		counter++;
		if (forPrint)
			cout << "successfully inserted!" << endl;
	}

	node* Find(int v) {
		node* carry = start;
		while (carry != NULL) {
			if (carry->value == v)
				break;
			carry = carry->Next;
		}
		return carry;
	}

	node* FindForDelete(int v) {
		node* carry = start;
		while (carry->Next != NULL) {
			if (carry->Next->value == v)
				return carry;
			carry = carry->Next;
		}
		return NULL;
	}

	void DeleteByValue(int v) {
		if (start == NULL) {
			cout << "list is empty!" << endl;
			return;
		}
		node* d = FindForDelete(v);
		if (d == NULL) {
			if (start->value == v) {
				node* del = start;
				start = start->Next;
				delete del;             //age jaye del, start ham bashe kar mikone!!!!
				cout << "successfully deleted!" << endl;
				counter--;
				return;
			}
			cout << "isn't exist" << endl;
			return;
		}
		cout << endl << start << endl << d << endl;
		node* del = d->Next;

		d->Next = d->Next->Next;
		delete del;
		cout << "successfully deleted!" << endl;
		counter--;
	}

	void Display() {
		//cout << start->value << endl;
		//cout << start->value << endl;
		if (start != NULL) {
			cout << "number of nodes : " << counter << endl;
			node* carry = start;
			while (carry != NULL) {
				cout << "---> " << carry->value << endl;
				carry = carry->Next;
			}
		}
		else
			cout << "list is empty!" << endl;
	}
};


struct bigNode {
	bigNode* Next;
	LinkedList value;
};

class BigLinkedList {
public:
	bigNode* start = NULL;
	int counter = 0;

public:
	BigLinkedList() {
		start = NULL;
	}
	void CreateList(LinkedList v) {
		bigNode* bn = new bigNode;
		bn->Next = NULL;
		bn->value = v;
		start = bn;
		counter++;
		cout << "successfully created!" << endl;
	}
	void InsertAtStart(LinkedList v) {
		bigNode* bn = new bigNode;
		bn->Next = start;
		bn->value = v;
		start = bn;
		counter++;
		cout << "successfully inserted!" << endl;
	}

	void InsertAtEnd(LinkedList v) {
		if (!start) {
			CreateList(v);
			return;
		}
		bigNode* bn = new bigNode;
		bigNode* carry = start;
		for (; carry->Next != NULL; carry = carry->Next);
		bn->value = v;
		bn->Next = NULL;
		carry->Next = bn;
		counter++;
		cout << "successfully inserted!" << endl;
		start->value.Display();
	}

	bigNode* Find(LinkedList v) {
		bigNode* carry = start;
		while (carry != NULL) {
			if (carry->value.start == v.start)
				break;
			carry = carry->Next;
		}
		return carry;
	}

	bigNode* FindForDelete(LinkedList v) {
		bigNode* carry = start;
		while (carry->Next != NULL) {
			if (carry->Next->value.start == v.start)
				return carry;
			carry = carry->Next;
		}
		return NULL;
	}

	void DeleteByValue(LinkedList v) {
		if (start == NULL) {
			cout << "list is empty!" << endl;
			return;
		}
		bigNode* d = FindForDelete(v);
		if (d == NULL) {
			if (start->value.start == v.start) {
				bigNode* del = start;
				start = start->Next;
				delete del;
				cout << "successfully deleted!" << endl;
				counter--;
				return;
			}
			cout << "isn't exist" << endl;
			return;
		}
		//cout << endl <<start << endl << d << endl;
		bigNode* del = d->Next;

		d->Next = d->Next->Next;
		delete del;
		cout << "successfully deleted!" << endl;
		counter--;
	}



	bigNode* FindByIndex(int c)
	{
		if (c == 1)
			return start;
		c--;
		if (c > 0 && c <= counter) {
			bigNode* carry = start;
			for (int i = 0; i < c; i++, carry = carry->Next);
			return carry;
		}

	}

	void Merge(int a, int b)
	{
		if (a > counter || a < 1 || b > counter || b < 1)
		{
			cout << "this index isn't exist! try another ..." << endl;
			return;
		}

		bigNode* first = FindByIndex(a);
		bigNode* second = FindByIndex(b);

		node* secCarry = second->value.start;
		for (; secCarry != NULL; secCarry = secCarry->Next)
			first->value.InsertAtEnd(secCarry->value, false);
		cout << "successfully merged!";
	}


	void Display() {
		//cout << start->value << endl;
		if (start != NULL) {
			cout << "number of nodes (main list) : " << counter << endl;
			bigNode* carry = start;
			while (carry != NULL) {
				//cout << "---> " << carry->value << endl;
				cout << "_________" << endl;
				carry->value.Display();
				carry = carry->Next;
			}
		}
		else
			cout << "main list is empty!" << endl;
	}
};


int main()
{
	int j;
	LinkedList linkedList;
	BigLinkedList bigLinkedList;

	bool boolean;
	cout << """''PLEASE INPUT JUST NUMBER''" << endl;
	while (1) {
		cout << "______________________________________________" << endl;
		cout << "**********************************************" << endl;
		PrintBigMenu();
		cout << "enter : ";
		cin >> j;
		boolean = true;

		switch (j) {
			case 1:
			{
				LinkedList linkedList;
				while (boolean) {
					cout << "_________________________" << endl;
					PrintMenu();
					cout << "enter : ";
					cin >> j;
					switch (j) {
						case 1:
						{
							int v;
							cout << "input value : ";
							cin >> v;
							linkedList.CreateList(v);
							break;
						}
						case 2:
						{
							cout << "input value : ";
							int v;
							cin >> v;
							linkedList.InsertAtStart(v);
							break;
						}

						case 3:
						{
							cout << "input value : ";
							int v;
							cin >> v;
							linkedList.InsertAtEnd(v, true);
							break;
						}
						case 4:
						{
							cout << "input value : ";
							int v;
							cin >> v;
							linkedList.DeleteByValue(v);
							break;

						}
						case 5:
						{
							linkedList.Display();
							break;
						}
						case 6:
						{
							bigLinkedList.InsertAtEnd(linkedList);
							//b.start->value.Display();
							boolean = false;
							break;
						}
						default:
						{
							cout << "input number 1 to 6!" << endl;
							break;
						}
					}
				}
				break;
			}

			case 2:
			{
				cout << "input number of linked list : ";
				cin >> j;
				if (j > bigLinkedList.counter || j < 1) {
					cout << "this index isn't exist! try another index ..." << endl;
					break;
				}
				linkedList = bigLinkedList.FindByIndex(j)->value;
				while (boolean) {
					cout << "_________________________" << endl;
					PrintMenu();
					cout << "enter : ";
					cin >> j;
					switch (j) {
						case 1:
						{
							int v;
							cout << "input value : ";
							cin >> v;
							linkedList.CreateList(v);
							break;
						}
						case 2:
						{
							cout << "input value : ";
							int v;
							cin >> v;
							linkedList.InsertAtStart(v);
							break;
						}
						case 3:
						{
							cout << "input value : ";
							int v;
							cin >> v;
							linkedList.InsertAtEnd(v, true);
							break;
						}
						case 4:
						{
							cout << "input value : ";
							int v;
							cin >> v;
							linkedList.DeleteByValue(v);
							break;
						}
						case 5:
						{
							linkedList.Display();
							break;
						}
						case 6: {
							boolean = false;
							break;
						}
						default:
						{
							cout << "input number 1 to 6!" << endl;
							break;
						}
					}
				}
				break;
			}

			case 3:
			{
				int first;
				int second;
				cout << "input first link list index : ";
				cin >> first;
				cout << "input second link list index : ";
				cin >> second;
				bigLinkedList.Merge(first, second);
				break;
			}

			case 4:
			{
				int forDel;
				cout << "input index of linked list to delete : ";
				cin >> forDel;
				if (forDel > bigLinkedList.counter || forDel < 1)
				{
					cout << "this index isn't exist! try another index ..." << endl;
					break;
				}
				bigNode* beDelete;
				beDelete = bigLinkedList.FindByIndex(forDel);
				bigLinkedList.DeleteByValue(beDelete->value);
				break;
			}

			case 5:
			{
				bigLinkedList.Display();
				break;
			}

			case 6:
			{
				exit(0);
			}

			default:
			{
				cout << "input number 1 to 6!" << endl;
				break;
			}
		}
	}
	return 0;
}

void PrintBigMenu() {
	cout << "1_add linked list" << endl;
	cout << "2_edit exist linked lists" << endl;
	cout << "3_merge link lists" << endl;
	cout << "4_delete by index" << endl;
	cout << "5_print all" << endl;
	cout << "6_EXIT" << endl;
}

void PrintMenu() {
	cout << "1_create linked list" << endl;
	cout << "2_insert at start" << endl;
	cout << "3_insert at end" << endl;
	cout << "4_delete item" << endl;
	cout << "5_print all" << endl;
	cout << "6_back" << endl;
}