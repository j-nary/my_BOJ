#include <iostream>
#include <string>

using namespace std;

int main() {
    string cro[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

    int cnt = 0;

    string input;
    cin >> input;
    
    for (long unsigned int i = 0; i < input.length(); i++) {
        //cout << "비교 : " << input[i] << " // i = " << i << endl;
        //cout << "substr() : " << input.substr(i, 2) << endl;
        if (!input.substr(i, 2).compare(cro[0]) || !input.substr(i, i+2).compare(cro[1])) {
            i++;  //cout << "실행c" << endl;
        }
        
        else if (!input.substr(i, 3).compare(cro[2])){
            i+=2;  //cout << "실행dz" << endl;
        }
        else if (!input.substr(i, 2).compare(cro[3])){
            i++;  //cout << "실행d-" << endl;
        }

        else if (!input.substr(i, 2).compare(cro[4])) {
            i++; //cout << "실행lj" << endl;
        }
        else if (!input.substr(i, 2).compare(cro[5])) {
            i++;  //cout << "실행nj" << endl;
        }
        else if (!input.substr(i, 2).compare(cro[6])) {
            i++; //cout << "실행s=" << endl;
        }
        else if (!input.substr(i, 2).compare(cro[7])) {
            i++; //cout << "실행z=" << endl;
        }    
        cnt++;
    }

    cout << cnt << '\n';

}