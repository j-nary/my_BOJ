#include <iostream>
#include <string>

using namespace std;

int main() {
    string cro[8] = {"c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z="};

    int cnt = 0;

    string input;
    cin >> input;
    
    for (long unsigned int i = 0; i < input.length(); i++) {
        //cout << "�� : " << input[i] << " // i = " << i << endl;
        //cout << "substr() : " << input.substr(i, 2) << endl;
        if (!input.substr(i, 2).compare(cro[0]) || !input.substr(i, i+2).compare(cro[1])) {
            i++;  //cout << "����c" << endl;
        }
        
        else if (!input.substr(i, 3).compare(cro[2])){
            i+=2;  //cout << "����dz" << endl;
        }
        else if (!input.substr(i, 2).compare(cro[3])){
            i++;  //cout << "����d-" << endl;
        }

        else if (!input.substr(i, 2).compare(cro[4])) {
            i++; //cout << "����lj" << endl;
        }
        else if (!input.substr(i, 2).compare(cro[5])) {
            i++;  //cout << "����nj" << endl;
        }
        else if (!input.substr(i, 2).compare(cro[6])) {
            i++; //cout << "����s=" << endl;
        }
        else if (!input.substr(i, 2).compare(cro[7])) {
            i++; //cout << "����z=" << endl;
        }    
        cnt++;
    }

    cout << cnt << '\n';

}