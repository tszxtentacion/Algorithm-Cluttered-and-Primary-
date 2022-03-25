#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100010;
int n, m, x, a[N], ans;

bool check1(int mid)
{
    if (a[mid] <= x)
        return true;
    return false;
}

bool check2(int mid)
{
    if (a[mid] >= x)
        return true;
    return false;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    cin >> m;
    while (m--)
    {
        cin >> x;
        int l = 0, r = n - 1, ll = 0, rr = 0;
        while (l < r)
        {
            int mid = (l + r + 1) / 2;
            if (check1(mid))
                l = mid;
            else
                r = mid - 1;
        }
        ll = l;
        l = 0, r = n - 1;
        while (l < r)
        {
            int mid = (l + r) / 2;
            if (check2(mid))
                r = mid;
            else
                l = mid + 1;
        }
        rr = l;
        if ((x - a[ll]) > (a[rr] - x))
            ans = a[rr];
        else
            ans = a[ll];
        cout << ans << endl;
    }
    return 0;
}