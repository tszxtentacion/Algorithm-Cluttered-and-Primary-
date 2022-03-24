#include <iostream>
using namespace std;
int n, ans;

void dfs(int t)
{
    if (t > n)
        return;
    if (t == n)
    {
        ans++;
        return;
    }
    for (int i = 1; i <= 6; i++)
        dfs(t + i);
    return;
}

int main()
{
    cin >> n;
    dfs(0);
    cout << ans << endl;
    return 0;
}