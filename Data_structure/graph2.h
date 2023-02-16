class Graph {
    private:
        int **adjmatrix;
        int num;
        int *check;
        int *dist;

    public:
        void LoadMatrix(std::string& filename);
        //인자로 받은 파일명으로 파일에 있는 가중치 행렬을 읽어 멤버변수에 저장
        int GetSize() { //행렬크기 반환
            return num;
        }
        void PrintMatrix();
        //인접 행렬 출력
        ~Graph() {
            for (int i = 0; i < num; i++)
                delete[] adjmatrix[i];
            
            delete[] adjmatrix;
        }
        void PrintShortestPathWeight(int s);
        //시작 정점 s로부터 나머지 v까지의 최단 경로 출력
        int Choose(int v);
};