//BOJ_2904 수학은 너무 쉬워[골드 3]
//우잉... 한 번에 맞아버려서 history가 없습니다...!
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

bool sosu[1000006];         //false이면 소수
int check[1000006];
map<int, int> m[1000006];    //소인수분해 저장
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    vector<int> v;  //input 저장
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        int input; cin >> input;
        v.push_back(input);
    }
    sort(v.begin(), v.end());

    //에라토스테네스의 체
    sosu[1] = true;
    sort(v.begin(), v.end());
    int maxInput = v[N-1];
    for (int i = 2; i*i <= maxInput; i++) {
        if (sosu[i] == true) continue;
        else {
            for (int j = i+i; j <= maxInput; j+=i) {
                sosu[j] = true;
            }
        }
    }


    for (int k = 0; k < N; k++) {
        int tmp = v[k];

        for (int i = 2; i < maxInput; i++) {
            if (tmp == 1) break;
            if (sosu[i]) continue;  //소수가 아니면 pass
            while(tmp % i == 0) {
                tmp /= i;
                check[i]++;
                if (m[v[k]].find(i) != m[v[k]].end()) {
                    m[v[k]].find(i)->second++;
                } else {
                    m[v[k]].insert({i, 1});
                }
            }
        }

    }

    int firstAns = 1;
    int secondAns = 0;
    for (int i = 2; i < maxInput; i++) {
        if (!check[i]) continue;
        check[i] /= N;
        firstAns *= pow(i, check[i]);
        for (int j = 0; j < N; j++) {
            if (m[v[j]].find(i) == m[v[j]].end()){
                secondAns += check[i];
            }else if (check[i] > m[v[j]].find(i)->second) {
                secondAns += (check[i] - m[v[j]].find(i)->second);
            }
        }
    }

    cout << firstAns << " " << secondAns << '\n';
}