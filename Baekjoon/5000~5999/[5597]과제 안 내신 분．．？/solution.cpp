#include <iostream>
#include <set>

using namespace std;

#define endl "\n"

set<int> students;
int N;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  for (int i = 1; i <= 30; i++)
    students.insert(i);

  for (int i = 0; i < 28; i++) {
    cin >> N;

    students.erase(N);
  }

  for (int res : students) {
    cout << res << endl;
  }

  return 0;
}