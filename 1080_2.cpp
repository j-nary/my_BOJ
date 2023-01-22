//BOJ_1080 행렬 [실버 1]
//2차원 배열이 참조에 의한 호출이라는 것을 고려하지 않고 설계한 알고리즘...
//깨달은 점 : 2차원배열을 call by value로 하고 싶을 땐 vector로!
//시간 초과 : DFS가 아니라 BFS로 짜야지!

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int> > A;
vector<vector<int> > B;

int isEqual(vector<vector<int> > tmp) {
    int flag = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (tmp[i][j] != A[i][j]) {
                flag = 0;
                break;
            }
        }
        if (flag == 0) break;
    }
    return flag;
}

void arr_copy(vector<vector<int> > &arr, vector<vector<int> > &dest) {
                                    //call by reference
    dest.clear();
    for (int i = 0; i < n; i++) {
        vector<int> tmp;
        for (int j = 0; j < m; j++) {
            tmp.push_back(arr[i][j]);
        }
        dest.push_back(tmp);
    }
}

int resFlag = 0;
int resCnt;
queue<pair<vector<vector<int> >, int> > q;
void reverseMatrix(vector<vector<int> > tmp) {
    q.push(make_pair(tmp, 0));
    while (!q.empty()) {
        tmp = q.front().first;
        int cnt = q.front().second + 1;
        q.pop();

        if (isEqual(tmp)) {
            cout << cnt << endl;
            resFlag = 1;
            return;
        }        

        for (int i = 0; i <= n - 3; i++) {
            for (int j = 0; j <= m - 3; j++) {
                vector<vector<int> > idx;
                arr_copy(tmp, idx);
                //3x3 뒤집기
                for (int k = i; k < i + 3; k++) {
                    for (int l = j; l < j + 3; l++) {
                        if (idx[k][l] == 1) idx[k][l] = 0;
                        else idx[k][l] = 1;
                    }
                }
                q.push(make_pair(idx, cnt));
            }
        }        
    }


}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string input; cin >> input;
        vector<int> tmp;
        for (int j = 0; j < m; j++) {
            tmp.push_back(input[j] - 48);
        }
        A.push_back(tmp);
    }

    for (int i = 0; i < n; i++) {
        string input; cin >> input;
        vector<int> tmp;
        for (int j = 0; j < m; j++) {
            tmp.push_back(input[j] - 48);
        }
        B.push_back(tmp);
    }
    vector<vector<int> > tmp;
    arr_copy(B, tmp);

    resCnt = n * m;
    reverseMatrix(tmp);
    if (!resFlag) cout << -1 << endl;


}