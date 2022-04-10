#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

struct Order {
  int n;
  int t;

  bool operator()(Order o) {
    return n == o.n;
  }
};

string op;
int N, M, o_table, o_time;
vector<Order> tables;

int cmp(Order a, Order b);
void print_tables();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  for (int i = 0; i < N; i++) {
    cin >> op;

    if (op == "order") {
      cin >> o_table >> o_time;

      Order o;
      o.n = o_table;
      o.t = o_time;

      tables.push_back(o);
    } else if (op == "complete") {
      cin >> o_table;

      Order o;
      o.n = o_table;
      tables.erase(find_if(tables.begin(), tables.end(), o));
    } else {
      sort(tables.begin(), tables.end(), cmp);
    }

    print_tables();
  }

  return 0;
}

int cmp(Order a, Order b) {
  return a.t != b.t ? a.t < b.t : a.n < b.n;
}

void print_tables() {
  if (tables.size() == 0) {
    cout << "sleep" << endl;
  } else {
    for (int i = 0; i < tables.size(); i++) {
      cout << tables[i].n << " ";
    }
    cout << endl;
  }
}