#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 100010;
typedef long long ll;
string s;
int f[N], st[30];
ll sum, x;

void update(char c)
{
    int aim = c - 'a';
    st[aim] = 0;
    for (int i = 0; i < 30; i++)
    {
        if (i != aim)
            st[i]++;
    }
}

int main()
{
    cin >> s;
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        x = x + st[s[i] - 'a'] + 1;
        sum = sum + x;
        update(s[i]);
    }
    cout << sum << endl;
    return 0;
}