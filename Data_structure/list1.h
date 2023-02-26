class LinkedList;
class Node {
    private:
        friend LinkedList;
        int data;
        Node *next;

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
        void Append(int data);      //List�� �������� ���ο� data Node �߰�
        int Length();               //List�� �ִ� Node�� �� return
        void Print();               //List�� �ִ� ��� Node�� head���� ���

};