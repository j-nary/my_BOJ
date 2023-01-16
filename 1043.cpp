//BOJ_1043 거짓말 [골드4]
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// class disjointSet {
//     private:
//         struct nodetype {
//             int parent;
//             int depth;
//         };
//         nodetype U[1000006];

//     public:
//         void makeset(int i) {
//             U[i].parent = i;
//             U[i].depth = 0;
//         }

//         //인덱스 i가 포함된 집합의 포인터 p를 넘겨줌
//         int find(int i) {
//             int j = i;
//             while(U[j].parent != j) j = U[j].parent;
//             return j;
//         }

//         //두 개의 집합을 가리키는 p와 q를 합병
//         void merge(int p, int q) {
//             if (U[p].depth == U[q].depth) {
//                 U[p].depth += 1;
//                 U[q].parent = p;
//             }
//             else if (U[p].depth < U[q].depth) U[p].parent = q;
//             else U[q].parent = p;
//         }

//         //p와 q가 같은 집합을 가리키면 true를 넘겨줌
//         bool equal(int p, int q) {
//             if (p == q) return true;
//             else return false;
//         }

//         //n개의 서로소 부분집합을 초기화
//         void initial(int n) {
//             for (int i = 1; i <= n; i++) makeset(i);
//         }
// };

int parent[52];
int knowing[52];
int isVis[52];

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    int knows; cin >> knows;
    for (int i = 0; i < knows; i++) {
        int tmp; cin >> tmp;
        knowing[tmp] = 1;
    }

    for (int i = 0; i < M; i++) {
        int many; cin >> many;
        int stand; cin >> stand;
        parent[stand] = stand;
        for (int j = 1; j < many; j++) {
            int tmp; cin >> tmp;
            parent[tmp] = stand;
        }
    }

    int cnt = 0;
    for (int i = 1; i < N; i++) {
        int idx = isVis[parent[i]];
        if (idx == 0) {
            int flag = 1;
            for (int i = 0; i < knows; i++) {
                if (parent[knowing[i]] == parent[i]) {
                    flag = 0;
                    break;
                }
            }
            if (flag == 0) continue;
            cnt++;
            isVis[parent[i]] = 1;
        }
    }
    
    cout << cnt << endl;

//     for (int i = 0; i < ; i++) {
//         int menu, a, b;
//         // cin >> menu >> a >> b;
//         scanf("%d%d%d", &menu, &a, &b);

//         int p = ds.find(a);
//         int q = ds.find(b);
        
//         switch(menu) {
//             case 0:
//                 ds.merge(p, q);
//                 break;
//             case 1:
//                 if (ds.equal(p, q)) printf("YES\n");
//                 else printf("NO\n");
//                 break;
//         }
//     }
}