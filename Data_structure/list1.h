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
        void Append(int data);      //List의 마지막에 새로운 data Node 추가
        int Length();               //List에 있는 Node의 수 return
        void Print();               //List에 있는 모든 Node를 head부터 출력

};
