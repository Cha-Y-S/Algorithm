S = input()
suffix = list()

while len(S) > 0:
    suffix.append(S)
    S = S[1:]

suffix.sort()

for s in suffix:
    print(s)
