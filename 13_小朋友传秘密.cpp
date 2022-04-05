#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100010;
int a[N], n, parent[N], ans;
bool st[N];

int find(int x)
{
    return parent[x] == x ? x : find(parent[x]);
}

// 把x1并入x2
void merge(int x1, int x2)
{
    int p1 = find(x1);
    int p2 = find(x2);
    parent[p1] = p2;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        scanf("%d", &a[i]);
    }
    for (int i = 1; i <= n; i++)
        parent[find(i)] = find(a[i]);
    for (int i = 1; i <= n; i++)
    {
        int root = find(i);
        if (!st[root])
        {
            st[root] = true;
            cout << root << ' ';
            ans++;
        }
    }
    cout << endl;
    cout << ans << endl;
    return 0;
}