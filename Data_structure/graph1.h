class Graph {
    private:
        int **adjmatrix;
        int num;

    public:
        void LoadMatrix(std::string& filename);
        //���ڷ� ���� ���ϸ����� ���Ͽ� �ִ� ����ġ ����� �о� ��������� ����
        void PrintMatrix();
        //���� ��� ���
        ~Graph() {
            for (int i = 0; i < num; i++)
                delete[] adjmatrix[i];
            
            delete[] adjmatrix;
        }

};