// 网格化，可以转换为网格问题
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
// 可用的小正方形的边长
int a[] = {0, 2, 5, 9, 11, 16, 17, 19, 21, 22, 24, 26, 30, 31, 33, 35, 36, 41, 46, 47, 50, 52, 61};
int len = 47 + 46 + 61, g[201][201];
bool vis[101], flag;

// 判断，坐标+选择的正方形的边长
bool judge(int x, int y, int w)
{
    // 超出范围
    if (x + w - 1 > len || y + w - 1 > len)
        return false;
    // 判断是否提前已经覆盖
    for (int i = x; i < x + w; i++)
        for (int j = y; j < y + w; j++)
            if (g[i][j])
                return false;
    return true;
}

// “填色”
void color(int x, int y, int w)
{
    int l;
    if (w == 0)
    {
        vis[g[x][y]] = false;
        l = g[x][y];
    }
    else
    {
        vis[w] = true;
        l = w;
    }
    for (int i = x; i < x + l; i++)
        for (int j = y; j < y + l; j++)
            g[i][j] = w;
}

void dfs(int x, int y)
{
    if (x == len + 1)
    {
        flag = true;
        return;
    }
    if (g[x][y])
    {
        if (y == len)
            dfs(x + 1, 1);
        else
            dfs(x, y + 1);
        return;
    }
    // 遍历每种小正方形
    for (int i = 1; i <= 22; i++)
    {
        if (vis[a[i]])
            continue;
        if (!judge(x, y, a[i]))
            break;
        color(x, y, a[i]);
        if (y == len)
            dfs(x + 1, 1);
        else
            dfs(x, y + 1);
        if (flag)
            return;
        color(x, y, 0);
    }
}

int main()
{
    memset(g, 0, sizeof g);
    memset(vis, false, sizeof g);
    color(1, 1, 47);
    color(1, 1 + 47, 46);
    color(1, 1 + 47 + 46, 61);
    dfs(1, 1);
    int color_ = -1;
    for (int i = 1; i <= len; i++)
    {
        if (g[len][i] != color_)
        {
            color_ = g[len][i];
            cout << color_ << endl;
        }
    }
    return 0;
}