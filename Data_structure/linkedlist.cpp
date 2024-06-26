#include <iostream>
#include <string>
#include <sstream>
#include "linkedlist.h"

using namespace std;

void LinkedList::Append(int data){      //List의 마지막에 새로운 data Node 추가
    if (cnt == 0) {
        head = new Node(data);
        tail = head;
    }
    else {
        Node *newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    cnt++;
}
void LinkedList::Prepend(int data) {
    if (cnt == 0) {
        head = new Node(data);
        tail = head;
    }
    else {
        Node *tmpNode = head;
        head = new Node(data);
        head->next = tmpNode;
        tmpNode->prev = head;
    }
    cnt++;
}
int LinkedList::Length(){               //List에 있는 Node의 수 return
    return cnt;
}
void LinkedList::Print(){
    Node *isin = head;
    while(isin->next != tail->next) {
        cout<< isin->data << " ";
        isin = isin->next;
    }
    cout << tail->data << endl;
} 

void LinkedList::PrintReverse() {
    Node *isin = tail;
    while(isin->prev != head->prev) {
        cout<< isin->data << " ";
        isin = isin->prev;
    }
    cout << head->data << endl;
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
