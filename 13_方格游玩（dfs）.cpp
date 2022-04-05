#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

const int N = 310;
char s[N][N];
bool st[N][N];
int n, m;
int ans = 90000;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};

void dfs(int i, int j, int count){
    if (i == n - 1 && j == m - 1){
        ans = min(ans, count);
        return;
    }
    
    st[i][j] = true;
    
    for (int k = 0; k < 4; k ++){
        int x = i + dx[k], y = j + dy[k];
        
        if (x < 0 || x >= n || y < 0 || y >= m) continue;
        if (st[x][y]) continue;
        if (s[i][j] == '2' && s[x][y] == '2') continue;
        
        if (s[x][y] == '2') dfs(x, y, count + 1);
        else dfs(x, y, count);
    }
    
    st[i][j] = false;
}

int main()
{
    cin >> n >> m;
    
    for (int i = 0; i < n; i ++){
        cin >> s[i];
    }
    
    dfs(0, 0, 0);
    
    if (ans == 90000) cout << -1 << endl;
    else cout << ans << endl;
    
    return 0;
}