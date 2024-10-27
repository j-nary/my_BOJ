#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    int  n;
    cin>>n;

    string ans = "int";
    while(n > 0){
      ans = "long " + ans;
      n -= 4;
    }

    cout<<ans;

    return 0;
}