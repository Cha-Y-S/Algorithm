import sys

trees = dict()
cnt = 0

for line in sys.stdin:
    tree = line.rstrip()
    if tree in trees:
        trees[tree] += 1
    else:
        trees[tree] = 1
    cnt += 1

for tree in sorted(trees.keys()):
    sys.stdout.write(f"{tree} {trees[tree]/cnt*100:0.4f}\n")
