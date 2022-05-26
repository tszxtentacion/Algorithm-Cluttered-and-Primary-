#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 25;
int g[N][N], r[N], c[N], walkr[N], walkc[N], n;
bool vis[N][N], flag; //  因为就一条路径，所以用flag表示是否找到
vector<int> vec;      //  用于记录路径
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};

// 检查是否符合输入的靶子
bool check()
{
    for (int i = 0; i < n; i++)
    {
        if (walkc[i] != c[i])
            return false;
        if (walkr[i] != r[i])
            return false;
    }
    return true;
}

void dfs(int a, int b)
{
    // 退出
    if (flag == 1)
        return;
    // 找到结果
    if (a == n - 1 && b == n - 1 && check())
    {
        flag = 1;
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << ' ';
        return;
    }
    // 递归遍历
    for (int i = 0; i < 4; i++)
    {
        int x = a + dx[i], y = b + dy[i];
        if (x < 0 || x >= n || y < 0 || y >= n || vis[x][y])
            continue;
        vis[x][y] = true;
        walkr[x]++;
        walkc[y]++;
        vec.push_back(x * n + y); //  记录路径
        dfs(x, y);
        vis[x][y] = false;
        walkr[x]--;
        walkc[y]--;
        vec.pop_back();
    }
    return;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < n; i++)
        cin >> r[i];
    walkr[0] = 1;
    walkc[0] = 1;
    vec.push_back(0);
    vis[0][0] = 1;
    dfs(0, 0);
    while (vec.size())
    {
        cout << vec.front();
        vec.pop_back;
    }
    return;
}