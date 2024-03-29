#include <iostream>
#include <set>
using namespace std;

long double s[1010][2];
long long ans;
bool st[1010];
pair<long double, long double> p;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s[i][0] >> s[i][1];
        set<pair<long double, long double> > points;

        for (int j = 0; j < i; j++)
        { //依次比较 查找重边
            if (st[j])
                continue; //直线是重边
            if (s[i][0] == s[j][0])
            { //斜率相同
                if (s[i][1] == s[j][1])
                {
                    st[i] = true;
                    break;
                }
                else
                    continue;
            }
            p.first = (s[j][1] - s[i][1]) / (s[i][0] - s[j][0]); //交点的x坐标
            p.second = s[i][0] * p.first + s[i][1];              //交点的y坐标
            points.insert(p);
        }
        if (!st[i])
            ans += points.size() + 1; //若不是重边，更新答案
    }
    cout << ans + 1;
}
