#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
const int N = 510;
typedef long long ll;
int m, n, h;
int f[50]; //��һά�����ʾ��ά״̬��������֮ǰ��01�������Ż�
ll ans;

int mian()
{
    cin >> m >> n;
    h = (int)(sqrt(2 * (m + n)));
    for (int s = 0; s < (1 << h); s++)
    {
        int tmpH = h, curS = s, cntA = 0, cntB = 0;
        // ��ʼ��������һ�У���Ϊ��������ж�ȡ����������һ��
        for (int i = tmpH; i >= 1; i--, curS>>= 1)
        {
            f[i] = curS & 1; // &1, ���ж����ұ���0����1
            if (f[i])
                cntA++;
            else
                cntB++;
        }
        // ��֤���������Ƿ�����Ҫ��
        while (tmpH--)
        {
            for (int i = 1; i <= tmpH; i++)
            {
                if (f[i + 1] == f[i])
                {
                    cntA++;
                    f[i] = 1;
                }
                else
                {
                    cntB++;
                    f[i] = 0;
                }
            }
        }
        // �жϣ����ۼƽ��
        if (cntA == m && cntB == n)
            ans++;
    }
    cout << ans << endl;
    return 0;
}
