//BOJ_6588 골드바흐의 추측 [실버 1]
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool sosu[1000006];
//false이면 소수
vector<int> v;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    sosu[1] = true;
    
    for (int i = 2; i*i <= 1000000; i++) {
        if (sosu[i] == true) continue;
        else {
            if (i != 2) v.push_back(i);
            for (int j = i+i; j <= 1000000; j+=i) {
                sosu[j] = true;
            }
        }
    }
    sosu[2] = true;

    int input;
    while(1) {
        cin >> input;
        if (input == 0) return 0;

        int a, b;
        bool flag = 1;
        for (int i = 0; i < v.size() && v[i] < input; i++) {
            a = v[i];
            b = input - v[i];
            if (b > 0 && sosu[b] == false) {
                flag = 0;
                break;
            } 
        }
        
        if (flag) cout << "Goldbach's conjecture is wrong.\n";
        else cout << input << " = " << a << " + " << b << '\n';
    }
}