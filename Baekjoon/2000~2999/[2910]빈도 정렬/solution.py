import sys

N, C = map(int, sys.stdin.readline().split())
inputData = list(map(int, sys.stdin.readline().split()))

freq = dict()
order = dict()
sorted = list()

for i in range(N):
    if inputData[i] in freq:
        freq[inputData[i]] += 1
    else:
        freq[inputData[i]] = 1

    if inputData[i] not in order:
        order[inputData[i]] = i

for key, value in freq.items():
    sorted.append([key, value])

sorted.sort(key=lambda x: (-x[1], order[x[0]]))

for i in range(len(sorted)):
    for j in range(sorted[i][1]):
        sys.stdout.write(str(sorted[i][0]) + " ")
sys.stdout.write("\n")
