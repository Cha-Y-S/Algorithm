import sys


class Order:
    def __init__(self, n, t):
        self.n = n
        self.t = t

    def __lt__(self, other):
        if self.t != other.t:
            return self.t < other.t
        else:
            return self.n < other.n


N, M = map(int, sys.stdin.readline().split())
tables = []


def print_tables():
    if len(tables) == 0:
        sys.stdout.write("sleep\n")
    else:
        for o in tables:
            sys.stdout.write(str(o.n) + " ")
        sys.stdout.write("\n")


for i in range(N):
    operation = list(sys.stdin.readline().split())

    if operation[0] == 'order':
        o_table, o_time = (int(operation[1]), int(operation[2]))

        tables.append(Order(o_table, o_time))
    elif operation[0] == 'complete':
        o_table = int(operation[1])

        for o in tables:
            if o.n == o_table:
                tables.remove(o)
    else:
        tables.sort()

    print_tables()
