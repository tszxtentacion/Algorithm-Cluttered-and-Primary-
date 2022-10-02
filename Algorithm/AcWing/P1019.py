n, m = map(int, input().strip().split())
v, w, s = [0], [0], [0]
for i in range(1, n+1):
    vv, ww, ss = map(int, input().strip().split())
    v.append(vv), w.append(ww), s.append(ss)

f = [0 for i in range(10010)]

# f[j][k] = max(f[j][k], f[j - v[i]][k-1] + w[i]) 已用容积，个数 // 总收益
for i in range(1, n + 1):
    for j in range(m, v[i] - 1, -1):
        for k in range(0, s[i] + 1):
            if j - k * v[i] >= 0:
                f[j] = max(f[j], f[j-v[i] * k] + k * w[i])

print(f[m])



