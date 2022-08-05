#include <cstdio>
#include <vector>

using namespace std;
int n, m;
vector<int> vec;
bool check[10];

void per() {
    if (vec.size() == m){
        for (int i=0; i < m; i++) {
            printf("%d ", vec[i]);
        }
    printf("\n");
    return;
    }

    for (int i=1; i <= n; i++) {
        if (check[i]) continue;
        vec.push_back(i);
        check[i] = 1;
        per();
        vec.pop_back();
        check[i] =0;
    }
}

int main() {
    scanf("%d %d", &n, &m);
    per();

    return 0;
}