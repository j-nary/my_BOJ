#include <iostream>
#include <string>
#include <sstream>
#include "list1.h"

using namespace std;

void LinkedList::Append(int data){      //List�� �������� ���ο� data Node �߰�
        if (cnt == 0) {
            head = new Node(data);
            tail = head;
        }
        else {
            Node *newNode = new Node(data);
            tail->next = newNode;
            tail = newNode;
        }
        cnt++;
}
int LinkedList::Length(){               //List�� �ִ� Node�� �� return
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

int main(void) {
    LinkedList list;
    
    string numbers;
    int number;
    getline(cin, numbers);
    
    istringstream is(numbers);
    while (is >> number) {
        list.Append(number);
    }
    
    list.Print();
    cout << list.Length() << endl;
    
    return 0;
}
