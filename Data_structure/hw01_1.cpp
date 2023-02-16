#include <iostream>

using namespace std;
int cbn(int, int);
int main() {

    int n, r;
    cin >> n >> r;

    int res = cbn(n, r);
    cout<<res<<endl;
    return 0;
}

int cbn(int n, int r) {
    if(n<r) return 0;
    if(r==n || r==0) return 1;
    else return (cbn(n-1, r-1) + cbn(n-1, r));
}