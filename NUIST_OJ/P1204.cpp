#include <iostream>
#include <cstring>

using namespace std;

int n, a[1007];
int main()
{
    while (cin >> n)
    {
        int sum = 0, maxv = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            sum += a[i];
            maxv = max(maxv, a[i]);
        }
        if (maxv >= sum - maxv)
            printf("%.1f\n", (double)sum - maxv);
        else
            printf("%.1f\n", sum / 2.0);
    }
    return 0;
}