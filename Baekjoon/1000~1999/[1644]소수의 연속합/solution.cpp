#include <iostream>
#include <map>
#include <vector>

using namespace std;

#define endl "\n"

vector<bool> eratos;
map<int, int> m;
int N, answer, m_key;

void make_sum(int i);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  eratos = vector<bool>(N + 1, true);
  answer = m_key = 0;

  eratos[0] = eratos[1] = false;

  for (int i = 2; i <= N + 1; i++) {
    if (!eratos[i]) continue;
    m[m_key++] = i;
    for (int j = i + i; j <= N + 1; j += i)
      eratos[j] = false;
  }

  int i = 0;

  while (i < m_key && m[i] <= N) {
    make_sum(i);
    i++;
  }

  cout << answer << endl;

  return 0;
}

void make_sum(int i) {
  int sum = 0;

  while (i < m_key) {
    sum += m[i];
    if (sum >= N) break;
    i++;
  }

  if (sum == N) answer++;
}