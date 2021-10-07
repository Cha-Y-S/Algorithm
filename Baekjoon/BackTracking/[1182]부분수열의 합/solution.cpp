#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

typedef pair<int, bool> pib;

vector<pib> input;
vector<int> sequence;
int N, S, choice, answer;

int calculate();
void combination(int idx, int cnt);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> S;

  input = vector<pib>(N, {0, false});
  sequence = vector<int>(N);
  answer = 0;

  for (int i = 0; i < N; i++)
    cin >> input[i].first;

  for (int i = 0; i < N; i++) {
    choice = i + 1;

    combination(0, 0);
  }

  cout << answer << endl;

  return 0;
}

void combination(int idx, int cnt) {
  if (cnt == choice) {
    int sum = calculate();

    if (sum == S) answer++;
  }

  for (int i = idx; i < N; i++) {
    if (input[i].second) continue;
    input[i].second = true;
    sequence[cnt] = input[i].first;
    combination(i + 1, cnt + 1);
    input[i].second = false;
  }
}

int calculate() {
  int result = 0;

  for (int i = 0; i < choice; i++)
    result += sequence[i];

  return result;
}