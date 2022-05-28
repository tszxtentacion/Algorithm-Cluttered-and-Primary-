#include <iostream>
#include <cstring>
#include <cstdio>
#include <set>
using namespace std;

int g[20][20];
set<string> st;

bool judge() // �ж��Ƿ�ͬɫ
{
    for (int i = 1; i < 3; i++)
        for (int j = 1; j < 10; j++)
        {
            if ((g[i][j] + g[i][j + 1] + g[i + 1][j] + g[i + 1][j + 1]) % 4 == 0)
                return false;
        }

    return true;
}

void dfs(int x, int y)
{
    if (x == 4)
    {
        if (judge())
        {
            string ans = "";
            for (int i = 1; i <= 3; i++)
                for (int j = 1; j <= 10; j++)
                {
                    char str[5];
                    sprintf(str, "%d", g[i][j]); // ����ת�ַ���
                    ans += str;
                }

            st.insert(ans);
        }
        return;
    }

    if (g[x][y] == -1) // ��û�̷Ŵ�ש
    {
        if (y + 1 <= 10 && g[x][y + 1] == -1) // ���ŷ�
        {
            for (int i = 0; i < 2; i++)
            {
                g[x][y] = g[x][y + 1] = i;
                if (y + 2 <= 10)
                    dfs(x, y + 2);
                else
                    dfs(x + 1, 1);
                g[x][y] = g[x][y + 1] = -1;
            }
        }

        if (x + 1 <= 3 && g[x + 1][y] == -1) // ���ŷ�
        {
            for (int i = 0; i < 2; i++)
            {
                g[x][y] = g[x + 1][y] = i;
                if (y + 1 <= 10)
                    dfs(x, y + 1);
                else
                    dfs(x + 1, 1);
                g[x][y] = g[x + 1][y] = -1;
            }
        }
    }
    else
    {
        if (y == 10)
            dfs(x + 1, 1); // ����
        else
            dfs(x, y + 1);
    }
}

int main()
{
    memset(g, -1, sizeof g);
    dfs(1, 1);
    cout << st.size() << endl;
    return 0;
}
