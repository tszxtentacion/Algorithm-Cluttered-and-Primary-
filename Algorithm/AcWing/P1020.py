n, m = map(int, input().strip().split())
k = int(input())
a, b, c = [0], [0], [0]
for i in range(1, k + 1):
    a_, b_, c_ = map(int, input().strip().split())
    a.append(a_)
    b.append(b_)
    c.append(c_)

# f[j][k] = min(f[j][k], f[j-a[i]][k-b[i]]+c[i])
f = [[1e9 for i in range(1003)] for j in range(1003)]
f[0][0] = 0
for i in range(1, k + 1):
    for j in range(n, -1, -1):
        for k in range(m, -1, -1):
            f[j][k] = min(f[j][k], f[max(j-a[i], 0)][max(k-b[i], 0)] + c[i])

print(f[n][m])
