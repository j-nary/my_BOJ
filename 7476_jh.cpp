#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
#include <array>
using namespace std;

int N, M, A[555], B[555], D[555][555];
pair<int,int> P[555][555];
array<int,3> F[555];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N; for(int i=1; i<=N; i++) cin >> A[i];
    cin >> M; for(int i=1; i<=M; i++) cin >> B[i];

    for(int i=1; i<=N; i++){
        array<int,3> mx = {0, 0, 0};
        for(int j=1; j<=M; j++){
            if(B[j] < A[i]) mx = max(mx, F[j]);
            if(B[j] == A[i]) D[i][j] = mx[0] + 1, P[i][j] = {mx[1], mx[2]};
        }
        for(int j=1; j<=M; j++) if(D[i][j] > F[j][0]) F[j] = {D[i][j], i, j};
    }

    int mx = 0, r = 0, c = 0;
    for(int i=1; i<=N; i++) for(int j=1; j<=M; j++) if(D[i][j] > mx) mx = D[i][j], r = i, c = j;

    stack<int> stk;
    for(int i=r, j=c; i!=0; tie(i,j)=P[i][j]) stk.push(A[i]);

    cout << mx << "\n";
    while(!stk.empty()) cout << stk.top() << " ", stk.pop();
}