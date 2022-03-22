#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 10010;
int a[N], n;
ll s[N], maxv = -70010, tmp = 0;
int main()
{
    while (scanf("%d", &n)!=EOF)
    {
        maxv = -610000;
        tmp = 0;
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        for (int i = 1; i <= n; i++)
        {
            tmp += a[i];
            if (tmp > maxv)
                maxv = tmp;
            if (tmp < 0)
                tmp = 0;
        }
        cout << maxv << endl;
    }
    return 0;
}