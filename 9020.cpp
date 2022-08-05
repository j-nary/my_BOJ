#include <cstdio>

bool prime[10004];

int main() {
    int T, n = 0, a = 0, b = 0;
    scanf("%d", &T);

    for (int i = 2; i*i <= 10000; i++) {
        if (prime[i] == false) {
            for (int j = i*i; j <= 10000; j += i){
                prime[j] = true;
            }
        }
    }

    while (T--) {
        scanf("%d", &n);
        a = b = n / 2;
        while (prime[a] == true || prime[b] == true) {
            a--;
            b++;    
        }
        printf("%d %d\n", a, b);
    }

    return 0;
}