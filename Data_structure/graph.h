class Graph {
    private:
        int **adjmatrix;
        int num;
        int *check;
        int *dist;
        int *path;

    public:
        void LoadMatrix(std::string& filename);
        //���ڷ� ���� ���ϸ����� ���Ͽ� �ִ� ����ġ ����� �о� ��������� ����
        int GetSize() { //���ũ�� ��ȯ
            return num;
        }
        void PrintMatrix();
        //���� ��� ���
        ~Graph() {
            for (int i = 0; i < num; i++)
                delete[] adjmatrix[i];
            
            delete[] adjmatrix;
        }
        void PrintShortestPath(int s);
        //���� ���� s�κ��� ������ v������ �ִ� ��� ���
        int Choose(int v);
        void PrintShortestPathWeight(int s);
        //���� ���� s�κ��� ������ v������ �ִ� ����� ����ġ �� ���
};