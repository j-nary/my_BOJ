#include<iostream>

using namespace std;

template <class T>
class Chain {
    private:
        class Node {
            private:
                T data;
                Node *link;
            public:
                Node() {
                    link = NULL;
                }
                Node(T d)
                    :data(d) {
                        link = NULL;
                    }
                Node(T d, Node *l)
                    :data(d), link(l) {
                    }
                T OutData() {
                    return data;
                }
                void PutData(T d) {
                    data = d;
                }
                Node *OutLink() {
                    return link;
                }
                void PutLink(Node *l) {
                    link = l;
                }
        };

        Node *rear;
        Node *front;
    
    public:
        Chain() {
            front = new Node();
            rear = front;
        }
        void Push(T d) {
            if (front == rear) {
                front->PutData(d);
            }
            else {
                Node *current = new Node(d);
                rear->PutLink(current);
                rear = current;
            }
        }
        void Allprint() {
            cout << "front�� ������ : " << front->OutData() << endl;
            //cout << "�� ���� ������ : " << ((list->front)+1)->data << endl;
            //cout << "�� ���� ������ : " << ((list->front)+2)->data << endl;
            //cout << "�� ���� ������ : " << ((list->front)+3)->data << endl;
            cout << "rear(top)�� ������ : " << rear->OutData() << endl;
        }
};

int main() {
    Chain<int> *jnary = new Chain<int>();
    int input = 0;
    int cnt = 5;
    cout << "ù��° ������ �Է� : ";
    cin >> input;
    jnary->Push(input);
    while (cnt--) {
        cout << "���� ������ �Է� : ";
        cin >> input;
        jnary->Push(input);
    }
    jnary->Allprint();
    return 0;
}