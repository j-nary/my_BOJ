class LinkedList;
class Node {
    private:
        friend LinkedList;
        int data;
        Node *next;
        Node *prev;

    public:
        Node(int data) {
            this->data = data;
        }
};

class LinkedList {
    private:
        Node *head;
        Node *tail;
        int cnt = 0;
    
    public:
        LinkedList() {
            tail = head;
        }
        void Append(int data);      //List�� �������� ���ο� data Node �߰�
        void Prepend(int data);     //List�� ó���� ���ο� data Node �߰�
        int Length();               //List�� �ִ� Node�� �� return
        void Print();               //List�� �ִ� ��� Node�� head���� ���
        void PrintReverse();        //List�� �ִ� ��� Node�� �������� ���

};
