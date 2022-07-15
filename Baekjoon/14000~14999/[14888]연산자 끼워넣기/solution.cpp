#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"

vector<int> operators;
vector<int> operand;
vector<int> comb;
int N, r_min, r_max;

void permutation(int cnt);
void calculate();

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  operators = vector<int>(4, 0);
  operand = vector<int>(N);
  comb = vector<int>(N - 1, 0);
  r_min = 1000000000;
  r_max = -1000000000;

  for (int i = 0; i < N; i++)
    cin >> operand[i];

  for (int i = 0; i < 4; i++)
    cin >> operators[i];

  permutation(0);

  cout << r_max << endl
       << r_min << endl;

  return 0;
}

void permutation(int cnt) {
  if (cnt == operand.size() - 1) {
    calculate();
    return;
  }
  for (int i = 0; i < operators.size(); i++) {
    if (operators[i] == 0) continue;
    operators[i]--;
    comb[cnt] = i;
    permutation(cnt + 1);
    operators[i]++;
  }
}

void calculate() {
  int sum = 0;

  switch (comb[0]) {
    case 0:
      sum = operand[0] + operand[1];
      break;
    case 1:
      sum = operand[0] - operand[1];
      break;
    case 2:
      sum = operand[0] * operand[1];
      break;
    case 3:
      sum = operand[0] / operand[1];
      break;
  }

  for (int i = 1; i < comb.size(); i++) {
    switch (comb[i]) {
      case 0:
        sum += operand[i + 1];
        break;
      case 1:
        sum -= operand[i + 1];
        break;
      case 2:
        sum *= operand[i + 1];
        break;
      case 3:
        sum /= operand[i + 1];
        break;
    }
  }

  r_min = r_min > sum ? sum : r_min;
  r_max = r_max < sum ? sum : r_max;
}