코드
#include <iostream>

using namespace std;

int main()
{

  int a, b;
  cin >> a >> b;

  if (a == 2)
  {
    if (b == 18)
    {
      cout << "Special";
    }
    else if (b > 18)
    {
      cout << "After";
    }
    else
      cout << "Before";
  }

  else if (a > 2)
  {
    cout << "After";
  }

  else
    cout << "Before";
}