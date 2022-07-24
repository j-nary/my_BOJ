#include <iostream>
#include <vector>

using namespace std;
vector<int> vec;

int main() {
    int N;
    cin >> N;

    int *Data = new int[N];
    for (int i = 0; i < N; i++) cin >> Data[i];

    vec.push_back(Data[0]);
    for (int i = 1; i < N; i++) {
        if (vec.back() > Data[i]) {
            vec.push_back(Data[i]);
           // cout << Data[i] << "    push_back" << endl;
        }
        //else if (vec.back() == Data[i]) continue;
        else {
            for (int j = vec.size()-1; j >= 0; j--) {
                if (j == 0 && vec.at(j) < Data[i]) {vec.at(j) = Data[i]; break;}
                else if (vec.at(j) > Data[i]) {
                   // cout << vec.at(j+1) << " << " << Data[i] << endl;
                    {vec.at(j+1) = Data[i]; break;}
                }
            }
        }
    }

    //for (int i = 0; i < vec.size(); i++) cout << vec.at(i); 

    cout << vec.size() << endl;
    return 0;
}