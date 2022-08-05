#include <iostream>
#include <algorithm>

using namespace std;

int N;
int num[12];
char op[11];
char tmp[11];
int Max, Min;
int flag = 0;

void cal() {
    int res = num[0];
    for (int i = 1, j = 0; i < N; i++, j++) {
        switch (tmp[j]) {
            case 43 :
                res += num[i];
                break;
            case 45 :
                res -= num[i];
                break;
            case 42 :
                res *= num[i];
                break;
            case 47 :
                res /= num[i];
                break;
        }
    }
    if (flag == 0) {
        Max = res;
        Min = res;
        flag = 1;
    }
    Max = max(Max, res);
    Min = min(Min, res);
}

void Permutations(const int H, const int T) {
    if ( H == T) {
        for (int i = 0; i <= T; i++)
            tmp[i] = op[i];
        cal();
    }
    else {
        for (int i = H; i <= T; i++) {
            swap(op[H], op[i]);
            Permutations(H+1, T);
            swap(op[H], op[i]);
        }
    }
    
    return;
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    int add, abs, mul, div;
    cin >> add >> abs >> mul >> div;

    for (int i = 0; i < N-1; i++) {
        if (add-- > 0) op[i] = '+';
        else if (abs-- > 0) op[i] = '-';
        else if (mul-- > 0) op[i] = '*';
        else if (div-- > 0) op[i] = '/';
    }

    Permutations(0, N-2);

    cout << Max << '\n' << Min << '\n';
}