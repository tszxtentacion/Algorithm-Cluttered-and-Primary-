#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100010;
int n, m, x, ans, a[N];

bool check(int mid)
{
    if (a[mid] <= x)
        return true;
    return false;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    while (m--)
    {
        scanf("%d", &x);
        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = (l + r + 1) / 2;
            if (check(mid))
                l = mid;
            else
                r = mid - 1;
        }
        cout << a[l] << endl;
    }
    return 0;
}
