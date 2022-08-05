#include <cstdio>
#include <algorithm>
using namespace std;

bool arr[1003];
int main() {
    int N; scanf("%d", &N);
    int ac[1003];
    for (int i=0; i < N; i++) {
        scanf("%d", &ac[i]);
    }
    sort(ac, ac+N);
    int start = ac[0];
    int end = ac[N-1];

    arr[1] = true;
    for(int i=2; i*i <= end; i++) {
        if (arr[i] == 0) {
            for (int j = i*i; j <= end; j+=i)
                arr[j] = true;
        }
    }

    int cnt=0;
    for (int i=0; i < N; i++) {
        if (arr[ac[i]] == false)
            cnt++;
    }

    printf("%d\n", cnt);

    return 0;
}