#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Edge {
    int weight;
    int v1;
    int v2;

    Edge(int w, int v1, int v2)
    : weight(w), v1(v1), v2(v2) {}
};

class disjointSet {
    private:
        struct nodetype {
            int parent;
            int depth;
        };
        nodetype U[7];

    public:
        void makeset(int i) {
            U[i].parent = i;
            U[i].depth = 0;
        }

        //인덱스 i가 포함된 집합의 포인터 p를 넘겨줌
        int find(int i) {
            int j = i;
            while(U[j].parent != j) j = U[j].parent;
            return j;
        }

        //두 개의 집합을 가리키는 p와 q를 합병
        void merge(int p, int q) {
            if (U[p].depth == U[q].depth) {
                U[p].depth += 1;
                U[q].parent = p;
            }
            else if (U[p].depth < U[q].depth) U[p].parent = q;
            else U[q].parent = p;
        }

        //p와 q가 같은 집합을 가리키면 true를 넘겨줌
        bool equal(int p, int q) {
            if (p == q) return true;
            else return false;
        }

        //n개의 서로소 부분집합을 초기화
        void initial(int n) {
            for (int i = 1; i <= 7; i++) makeset(i);
        }
};

bool compare (const Edge &e1, const Edge &e2) {
    if(e1.weight < e2.weight) {
        return true;
    }
    else return false;
}

void kruskal (int n, int m, vector<Edge> E, vector<pair<int, int> > &F) {
    sort(E.begin(), E.end(), compare);

    disjointSet ds;
    ds.initial(n); //vertex 각각의 집합에 넣는 작업

    for (int idx = 0; F.size() < n-1; idx++) {
        int e = E[idx].weight;
        int i = E[idx].v1;
        int j = E[idx].v2;

        int p = ds.find(i);
        int q = ds.find(j);

        if (!ds.equal(p, q)) {
            ds.merge(p, q);
            F.push_back(make_pair(i, j));
        }
    }
}

int main() {
    vector<Edge> E;
    E.push_back(Edge(1, 1, 2));
    E.push_back(Edge(3, 1, 3));
    E.push_back(Edge(3, 2, 3));
    E.push_back(Edge(6, 2, 4));
    E.push_back(Edge(2, 3, 5));
    E.push_back(Edge(4, 3, 4));
    E.push_back(Edge(5, 4, 5));

    vector<pair<int, int> > F;

    kruskal(5, E.size(), E, F);

    for (int i = 0; i < F.size(); i++) {
        cout << F[i].first << " - " << F[i].second << endl;
    }
}