#include <cstdio>

bool check[10004];
int self_num(int);

int main() {
    for (int i=1; i <= 10000; i++) {
        check[self_num(i)] = true;
    }

    for (int i=1; i<= 10000; i++) 
        if (check[i] == false)
            printf("%d\n", i);
    
    return 0;
}

int self_num(int N) {
    int tmp = N;
    while (N) {
        tmp += N % 10;
        N /= 10;
    }
    return tmp;
}