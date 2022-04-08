#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
const int N = 23;
typedef pair<double, double> line;
typedef long long ll;
ll ans;
map<line, bool> mp;
int main()
{
    for (int x1 = 0; x1 < 20; x1++)
        for (int y1 = 0; y1 < 21; y1++)
        {
            for (int x2 = 0; x2 < 20; x2++)
            {
                if (x1 == x2)
                    continue;
                for (int y2 = 0; y2 < 21; y2++)
                {
                    if (y1 == y2)
                        continue;
                    double k = (y2 - y1) / (x2 - x1) * 1.0;
                    double b;
                    if (x1 == 0)
                        b = y1 * 1.0;
                    else if (x2 == 0)
                        b = y2 * 1.0;
                    else
                    {
                        double fm = (x2 - x1) * 1.0;
                        b = (y1*x2 - x1*y2) * 1.0 / fm;
                    }
                    line l;
                    l.first = k, l.second = b;
                    mp[l] = true;
                }
            }
        }
    for (auto iter = mp.begin(); iter != mp.end(); ++iter)
    {
        if (iter->second)
            ans++;
    }
    ans += (20 + 21);
    cout << ans << endl;
    return 0;
}