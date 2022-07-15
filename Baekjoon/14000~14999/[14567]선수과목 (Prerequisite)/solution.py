N, M = list(map(int, input().split()))

parent = [[] for i in range(N+1)]
child = [0 for i in range(N+1)]
res = [0 for i in range(N+1)]


def topological_sort():
    q = []

    for i in range(1, N + 1):
        if(child[i] == 0):
            q.append((i, 1))

    while len(q) > 0:
        cv, cc = q.pop(0)

        res[cv] = cc

        for i in range(len(parent[cv])):
            child[parent[cv][i]] -= 1
            if(child[parent[cv][i]] == 0):
                q.append((parent[cv][i], cc + 1))


def print_res():
    for i in range(1, N + 1):
        print(res[i], end=" ")


if __name__ == "__main__":
    for i in range(M):
        pre, post = list(map(int, input().split()))

        parent[pre].append(post)
        child[post] += 1

    topological_sort()

    print_res()
