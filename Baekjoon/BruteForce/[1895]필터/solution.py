R, C = map(int, input().split())
img = [[0 for i in range(C)]for j in range(R)]
res = 0

for i in range(R):
    img[i] = list(map(int, input().split()))

T = int(input())

for i in range(R - 2):
    for j in range(C - 2):
        tmp = []

        for ti in range(3):
            for tj in range(3):
                tmp.append(img[i+ti][j+tj])

        tmp.sort()

        if(tmp[4] >= T):
            res += 1

print(res)
