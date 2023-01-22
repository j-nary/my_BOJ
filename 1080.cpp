//BOJ_1080 행렬 [실버 1]
//2차원 배열이 참조에 의한 호출이라는 것을 고려하지 않고 설계한 알고리즘...
//깨달은 점 : 2차원배열을 call by value로 하고 싶을 땐 vector로!

#include <iostream>
#include <algorithm>
#include <vector>

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

//내가 지금 DFS인 걸 모르고 있었어 BFS인 줄 알았어...
int resFlag = 0;
int resCnt;
void reverseMatrix(int cnt, vector<vector<int> > tmp) {
    if (cnt > n * m) return;
    cnt++;

    if (isEqual(tmp)) {
        resFlag = 1;
        if (resCnt > cnt) resCnt = cnt;
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

            reverseMatrix(cnt, idx);
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
    reverseMatrix(-1, tmp);
    if (resFlag) cout << resCnt << endl;
    else cout << -1 << endl;


}