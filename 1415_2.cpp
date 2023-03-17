//BOJ_1415 사탕 [골드 1]
//사탕 가격의 합이 소수
//(1, 2, 1, 3, 1), (3, 1, 1, 1, 2) 는 한 가지로 취급
//시간초과
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool sosu[500005];   //false이면 소수
int N;
vector<int> input;
vector<pair<int, vector<int> > > check;
void knapsack (int depth, int price, vector<int> v) {
    //종료 조건
    if (depth == N) {
        if (sosu[price]) return;    //소수가 아니면 탈출
        int flag = 1;
        sort(v.begin(), v.end());
        for (int i = 0; i < check.size(); i++) {    //중복 체크
            if (check[i].first != price) continue;
            for (int j = 0; j < check[i].second.size(); j++) {
                if (v[j] != check[i].second[j]) {
                    flag = 1;
                    break;
                } else {
                    flag = 0;
                }
            }
            if (!flag) break;
        }
        if (flag) {     //중복 없으면 집어넣기
            check.push_back(make_pair(price, v));
        }
        return;
    }

    knapsack(depth + 1, price, v);
    v.push_back(input[depth]);
    knapsack(depth + 1, price + input[depth], v);
    
}
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    cin >> N;    // 1 <= N <= 50
    //0 <= 가격 <= 10,000
    int tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        input.push_back(tmp);
    }

    //소수판별
    sosu[1] = sosu[0] = true;
    for (int i = 0; i * i < 500005; i++) {
        if (sosu[i]) continue;
        for (int j = i + i; j < 500005; j += i) {
            sosu[j] = true;
        }
    }
    vector<int> v;
    knapsack(0, 0, v);
    cout << check.size() << '\n';
    
}