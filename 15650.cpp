#include <cstdio>
#include <vector>

using namespace std;
vector<int> vec;
int n, m;
bool check[10];

void com() {
    if (vec.size() == m){
        for (int i=0; i<m; i++) printf("%d ", vec[i]);
        printf("\n");
    return;
    }

    for (int i=1; i<=n; i++) {
        if (!vec.empty() && vec.back() >= i) continue;
        vec.push_back(i);
        com();
        vec.pop_back();
    }
}
int main() {
    scanf("%d %d", &n, &m);
    com();
    return 0;
}