#include <iostream>
#include <string>
using namespace std;
int main()
{
    int cnt=0;
    while(1)
    {
        int n;
        cin >> n;
        if ( n == -1)
            return 0;

        int sum = 0;
        int max = 1;
        for (int i=1; i<n; i++)
        {
            if ( n % i == 0)
            {
                sum += i;
                max = i;
            }
        }
        
        if (sum == n)
        {
            cout << n << " = ";
            for (int i=1; i<n; i++)
            {
                if (n % i == 0 && i != max)
                    cout << i << " + ";
                if ( i == max)
                    cout << i << endl;
            }
        }
        else
            cout << n << " is NOT perfect.\n";
    }
    
    return 0;
}
