#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
const int maxn = 100005;
vector<int> path;            // 当前路径
bool vis[maxn];
vector<int> G[maxn];        // 临接表
int father[maxn];       // 并查集
int getFather(int x){   // 找并查集 根节点, 同时路径压缩
    int t = x;
    while (father[x] != x)
        x = father[x];
    // x 已为根, 开始压缩路径
    while (t != x){
        int curF = father[t];
        father[t] = x;
        t = curF;
    }
    return x;
}
// 起点, 终点
int s, d;
void dfs(int node){
    vis[node] = true;
    path.push_back(node);
    if (node == d){
        if (path.size() == 2)
            return;
        // 题目要求排序输出
        sort(path.begin(), path.end());
        for (int i = 0; i < path.size(); i++)
            printf("%d ", path[i]);
        return;
    }
    for (int i = 0; i < G[node].size(); i++){
        int cur = G[node][i];
        if (!vis[cur])
            dfs(cur);
    }
    path.pop_back();
    vis[node] = false;
}
int main(){
    int N;
    scanf("%d", &N);
    // 初始化并查集
    for (int i = 1; i <= N; i++)
        father[i] = i;
    for (int i = 0; i < N; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        if (a > b)
            swap(a, b);
        int ra = getFather(a);
        int rb = getFather(b);
        // ra 和 rb 已经连通, 新加入的边 (a, b) 构成环
        if (ra == rb){
            s = a;  // 起点
            d = b;  // 终点
        } else     // 否则合并连通分支
            father[b] = a;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(s);
    return 0;
}