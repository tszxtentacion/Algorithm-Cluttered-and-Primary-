#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
using namespace std;
const int N = 9;
// typedef pair<int, int> PII;
// queue<PII> q;
char g[N][N];
int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
bool vis[N][N];
char path[N][N];

struct node
{
    int x, y;     //当前方块位置
    int pre = -1; //前驱方块的下标
} q[100010];

int front = -1, rear = -1;

void print(int last)
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (g[i][j] == '*')
                g[i][j] = 'O';
    int k = last;
    while (k != -1)
    {
        g[q[k].x][q[k].y] = ' ';
        k = q[k].pre;
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
            cout << g[i][j];
        cout << endl;
    }
}

void bfs(int a, int b)
{
    node p;
    p.x = a, p.y = b, p.pre = -1;
    g[p.x][p.y] = '*';
    rear++;
    q[rear] = p;
    while (front != rear)
    {
        node tmp = q[++front];
        if (tmp.x == 7 && tmp.y == 7)
        {
            print(front);
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            node cur;
            int x = tmp.x + dx[i], y = tmp.y + dy[i];
            cur.x = x, cur.y = y;
            if (x < 0 || x > 7 || y < 0 || y > 7 || g[x][y] == 'X' || g[x][y] == '*')
                continue;
            g[x][y] = '*';
            cur.pre = front;
            rear++;
            q[rear] = cur;
        }
    }
}

int main()
{
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
            cin >> g[i][j];
    bfs(0, 0);
    return 0;
}
