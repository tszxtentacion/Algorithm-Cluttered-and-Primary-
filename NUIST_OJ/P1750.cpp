#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N = 500010;
int a[N], n;
ll ans;

void merge(int l, int mid, int r)
{
    int i = l, j = mid + 1;
    int tmp[r - l + 1], k = 0;
    while (i <= mid && j <= r)
        if (a[i] <= a[j])
            tmp[k++] = a[i++];
        else
        {
            ans += mid - i + 1;
            tmp[k++] = a[j++];
        }
    while (i <= mid)
        tmp[k++] = a[i++];
    while (j <= r)
        tmp[k++] = a[j++];
    for (int i = 0; i < r - l + 1; i++)
        a[l + i] = tmp[i];
}

void merge_sort(int l, int r)
{
    if (l < r)
    {
        int mid = (l + r)  / 2;
        merge_sort(l, mid);
        merge_sort(mid + 1, r);
        merge(l, mid, r);
    }
}

int main()
{
    while (scanf("%d", &n) != EOF)
    {
        ans = 0;
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        merge_sort(0, n - 1);
        cout << ans << endl;
    }
    return 0;
}