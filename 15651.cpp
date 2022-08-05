#include <cstdio>
#include <vector>

using namespace std;
int n, m;
vector<int> vec;

void per()
{
    if (vec.size() == m)
    {
        for (int i = 0; i < m; i++)
        {
            printf("%d ", vec[i]);
        }
        printf("\n");
        return;
    }

    for (int i = 1; i <= n; i++)
    {
        vec.push_back(i);
        per();
        vec.pop_back();
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    per();

    return 0;
}