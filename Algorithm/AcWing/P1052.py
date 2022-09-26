def get_next(s):
    """
    获取kmp算法的next数组
    """
    next = [0 for i in range(len(s) + 2)]
    i, j = 2, 0
    for i in range(2, len(s)-1):
        while j and s[i] != s[j + 1]:
            j = next[j]
        if s[i] == s[j + 1]:
            j += 1
        next[i] = j
    return next


n = int(input())
s = input()
s = ' ' + s + ' '
m = len(s) - 2
next = get_next(s)
MOD = 1e9+7
f = [[0 for j in range(55)] for i in range(55)]     # 已经匹配了0位，且匹配的子串位置是0时的方案数为1
f[0][0] = 1
for i in range(n):
    for k in range(26):
        for j in range(m):
            u = j
            c = chr(k+97)   # 转换成字符
            # 当密码已经生成了k位，且第i+1位的字符是c，模版串的位置是j，得到能跳到哪个位置
            while u and s[u+1] != c:
                u = next[u]
            if s[u + 1] == c:
                u += 1
            if u < m:
                f[i+1][u] = (f[i+1][u] + f[i][j]) % MOD

ans = 0
for i in range(m):
    ans = (ans + f[n][i]) % MOD
print(int(ans))



