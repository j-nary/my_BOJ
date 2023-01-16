#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class disjointSet {
    private:
        struct nodetype {
            int parent;
            int depth;
        };
        nodetype U[1000006];

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
            for (int i = 0; i <= n; i++) makeset(i);
        }
};

int plan[1003];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    disjointSet ds;
    ds.initial(n);

    for(int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int tmp; cin >> tmp;
            if (tmp == 1) {
                int p = ds.find(i);
                int q = ds.find(j);
                ds.merge(p, q);
            }
        }
    }
    for(int i = 0; i < m; i++) {
        cin >> plan[i];
    }

    int flag = 1;

    for (int i = 0; i < m-1; i++) {
        int p = ds.find(plan[i]);
        int q = ds.find(plan[i + 1]);

        if (!ds.equal(p, q)) {
            flag = 0;
            break;
        }
    }

    if (flag == 1) cout << "YES" << endl;
    else cout << "NO" << endl;
}