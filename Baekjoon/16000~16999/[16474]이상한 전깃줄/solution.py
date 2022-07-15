import sys

N, M = map(int, sys.stdin.readline().split())
n_input = list(map(int, sys.stdin.readline().split()))
m_input = list(map(int, sys.stdin.readline().split()))
K = int(sys.stdin.readline())
l_pole, r_pole = [dict(), dict()]
connected = [[] for i in range(K)]
lis = []


def lower_bound(value):
    low = 0
    high = len(lis)

    while low < high:
        mid = (low + high) // 2

        if value <= lis[mid]:
            high = mid
        else:
            low = mid + 1

    return high


for i in range(N):
    l_pole[n_input[i]] = i

for i in range(M):
    r_pole[m_input[i]] = i

for i in range(K):
    inputData = list(map(int, sys.stdin.readline().split()))

    connected[i] = [l_pole[inputData[0]], r_pole[inputData[1]]]

connected.sort(key=lambda x: (x[0], -x[1]))

for i in range(K):
    idx = lower_bound(connected[i][1])

    if idx == len(lis):
        lis.append(connected[i][1])
    else:
        lis[idx] = connected[i][1]

sys.stdout.write(str(K - len(lis)) + "\n")
