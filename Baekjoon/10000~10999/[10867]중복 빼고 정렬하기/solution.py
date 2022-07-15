N = int(input())
s = set()

input_list = list(map(int, input().split()))

for i in range(N):
    s.add(input_list[i])

s = sorted(s)

for n in s:
    print(n, end=" ")
