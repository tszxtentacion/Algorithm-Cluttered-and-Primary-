n, k = map(int, input().strip().split())
s = list(map(int, input().strip().split()))
f = [[-1e9 for j in range(k+1)] for i in range(2)]
f[0][0] = 0

for i in range(n):
    for j in range(k, 0, -1):
        f[0][j] = max(f[0][j], f[1][j] + s[i])
        f[1][j] = max(f[1][j], f[0][j-1] - s[i])

ans = 0
for j in range(k + 1):
    ans = max(ans, max(f[0][j], f[1][j]))

print(ans)

