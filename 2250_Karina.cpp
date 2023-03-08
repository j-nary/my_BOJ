#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int MAX = 10004;
int N;
int cnt = 1;    // inorder 함수에서 트리의 열번호 세기 위한 변수 선언
// pair<int, int>nodes[크기]
pair<int, int> nodes[MAX];   // index는 노드 번호, first는 해당 노드의 왼쪽 자식 노드, second는 해당 노드의 오른쪽 자식 노드
vector<bool> isRoot(MAX, true); // 각 노드가 root인지 판별하기 위한 vector
// vector<bool> visited(MAX, false);  
int levels[MAX]; // 각 노드의 level을 저장하는 vector
int col[MAX];    // 각 노드의 열 값 저장하는 vector
// pair<int, int> tree[MAX];   // 트리를 이루는 각 노드의 행, 열 값 저장하는 vector
pair<int, int> ans; // 최대 너비와 최대 너비를 가지는 level 저장


void fastIo() {
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

void inorder(int v) {
    if (nodes[v].first != -1) inorder(nodes[v].first);
    // levels[v]행 i열에 v노드 저장
    // tree[v].first = levels[v];
    // tree[v].second = i;
    col[v] = cnt;

    // cout << levels[v] << "행 " << i << "열에 " << v << "노드 저장\n";
    cnt++;

    if (nodes[v].second != -1) inorder(nodes[v].second);
}


void findMax(int v) {
    int minrow, maxrow;

    for (int i = 1; i <= N; i++) {
        if (levels[i]) {    // i번 노드의 행
            minrow = maxrow = col[i];
            for (int j = 1; j <= N; j++) {
                if (levels[i] == levels[j]) {
                    // cout << "두 노드의 행이 다음으로 같음 : " << i << ' ' << j << ' ' << tree[i].first << '\n';
                    if (col[j] < minrow) minrow = col[j];
                    if (col[j] > maxrow) maxrow = col[j];
                }
            } 
            // cout << levels[i] << " 행의 최종 min, max : " << minrow << ' ' <<  maxrow << '\n';
        }
        int tmp = maxrow - minrow + 1;
        if (tmp > ans.second) {
            ans.second = tmp;
            ans.first = levels[i];
        } else if (tmp == ans.second && ans.first > levels[i]) {
            ans.first = levels[i];
        }

    }

}

int main() {
    fastIo();

    fill_n(levels, MAX, 1);
    fill_n(col, MAX, 1);
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        int n, l, r;
        cin >> n >> l >> r;
        nodes[n].first = l;
        nodes[n].second = r;

        // level 벡터의 각 노드에 (부모 노드 level + 1) 값을 저장
        levels[l] = levels[n] + 1;
        levels[r] = levels[n] + 1;

        // 자식 노드는 루트 노드가 될 수 없다
        if (l != -1) isRoot[l] = false;
        if (r != -1) isRoot[r] = false;
    }
    int root;
    for (int i = 1; i <= N; i++) if(isRoot[i]) root = i;


    inorder(root);

    findMax(root);

    cout << ans.first << ' ' << ans.second;
    
}