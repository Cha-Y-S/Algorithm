N, L = map(int, input().split())
H = sorted(list(map(int, input().split())))

for i in range(N):
    if H[i] > L:
        break

    L += 1

print(L)
