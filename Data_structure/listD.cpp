//#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include "listD.h"
using namespace std;

void LinkedList::Prepend(int data) {
	Node* newnode = new Node;
	Node* pnode = new Node;
	newnode->data = data;
	newnode->nextnode = head;
	pnode = newnode;
	head = newnode;
	newnode->prev = pnode;
}

void LinkedList::Append(int data) {
	Node* newnode = new Node;
	newnode->data = data;
	newnode->nextnode = NULL;
	if (head == NULL) {
		head = newnode;
		
	}
	else {

		Node* tempnode = head;
		while (tempnode->nextnode != NULL) {
			Node* pnode = tempnode;
			tempnode = tempnode->nextnode;
			tempnode->prev = pnode;
		}
		tempnode->nextnode = newnode;
		
	}
}

int LinkedList::Length() {
	int i=0;
	Node* checknode = head;
	while (checknode->nextnode!=NULL) {
		checknode = checknode->nextnode;
		i++;

	}
	
	return i;
}

void LinkedList::Print() {
	//Node* printnode = head;

	if (head == NULL) {
		//cout << printnode->data;
		cout << "" << endl;
	}
	else {
		Node* printnode = head;
		//printnode = printnode->nextnode;
			while (1) {
				if (printnode->data == 0) {
					printnode = printnode->nextnode;
					if (printnode == NULL) {
						cout << "" << endl;
						break;
					}
				}
				cout << printnode->data << " ";
				printnode = printnode->nextnode;
				if (printnode == NULL) {
					cout << "" << endl;
					break;
				}
			}
		}
}

void LinkedList::PrintReverse() {
	Node* printnode = head;
	tail = head;

	while (1) {
		printnode = printnode->nextnode;
		if (printnode == NULL) {
			break;
		}
		else
			tail = printnode;
	}
	while (1) {
		if (printnode->data == 0) {
			printnode->prev = printnode;
			if (printnode == head) {
				cout << "" << endl;
				break;
			}
		}
		cout << printnode->data << " ";
		printnode->prev = printnode;
		if (printnode == head) {
			cout << "" << endl;
			break;
		}

	}	
}

int main(void) {
    LinkedList list;
    
    string numbers;
    int number;
    getline(cin, numbers);
    
    istringstream is(numbers);
    while (is >> number) {
        if (number % 2)
            list.Append(number);
        else
            list.Prepend(number);
    }
    
    list.PrintReverse();
    cout << list.Length() << endl;
    
    return 0;
}