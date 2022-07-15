NA, NB = map(int, input().split())

A = set(map(int, input().split()))
B = set(map(int, input().split()))

s = sorted(list(A.difference(B)))

print(len(s))

for num in s:
    print(num, end=" ")
print()
