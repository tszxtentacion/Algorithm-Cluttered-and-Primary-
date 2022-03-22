#include <iostream>
#include <algorithm>
using namespace std;
int g[8][8];
long long ans;
bool st[8];
bool check(int x, int y)
{
    for (int i = 0; i < 8; i++)
        if (g[i][y] == 1 && i != x)
            return false;
    for (int i = 0; i < 8; i++)
        if (g[x][i] == 1 && i != y)
            return false;
    for (int i = x, j = y; i < 8 && j < 8; i++, j++)
        if (g[i][j] == 1 && (i != x && j != y))
            return false;
    for (int i = x, j = y; i < 8 && j >= 0; i++, j--)
        if (g[i][j] == 1 && (i != x && j != y))
            return false;
    for (int i = x, j = y; i >= 0 && j < 8; i--, j++)
        if (g[i][j] == 1 && (i != x && j != y))
            return false;
    for (int i = x, j = y; i >= 0 && j >= 0; i--, j--)
        if (g[i][j] == 1 && (i != x && j != y))
            return false;
    return true;
}

// 因为同一行显然不能再摆，所以用行作为参数即可
void find(int r)
{
    if (st[r])
    {
        find(r+1);
        return ;
    }
    if (r > 7)
    {
        ans++;
        return;
    }
    for (int c = 0; c < 8; c++)
    {

        if (check(r, c))
        {
            g[r][c] = 1;
            find(r + 1);
            g[r][c] = 0;
        }
    }

    return;
}

int main()
{
    int tmp;
    while (cin >> tmp)
    {
        ans = 0;
        g[0][0] = tmp;
        for (int i = 1; i < 8; i++)
            scanf("%d", &g[0][i]);
        for (int i = 1; i < 8; i++)
            for (int j = 0; j < 8; j++)
                scanf("%d", &g[i][j]);
        // 记录已有皇后的行
        for (int i = 0; i < 8; i++)
            for (int j = 0; j < 8; j++)
                if (g[i][j] == 1)
                {
                    st[i] = true;
                    break;
                }
        find(0);
        cout << ans << endl;
    }
    return 0;
}