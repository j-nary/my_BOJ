class Graph {
    private:
        int **adjmatrix;
        int num;

    public:
        void LoadMatrix(std::string& filename);
        //인자로 받은 파일명으로 파일에 있는 가중치 행렬을 읽어 멤버변수에 저장
        void PrintMatrix();
        //인접 행렬 출력
        ~Graph() {
            for (int i = 0; i < num; i++)
                delete[] adjmatrix[i];
            
            delete[] adjmatrix;
        }

};