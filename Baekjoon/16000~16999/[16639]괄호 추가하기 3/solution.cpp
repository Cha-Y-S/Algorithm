#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define endl "\n"

vector<vector<int>> max_result, min_result;
string expression;
int N;

void fast_io();
void init_result();
int calculate(int left, int right, char oper);

int main() {
  fast_io();

  cin >> N >> expression;

  max_result = vector<vector<int>>(N, vector<int>(N, INT_MIN));
  min_result = vector<vector<int>>(N, vector<int>(N, INT_MAX));

  init_result();

  for (int j = 2; j < N; j += 2) {
    for (int i = 0; i < N - j; i += 2) {
      for (int k = 2; k <= j; k += 2) {
        vector<int> candidate;

        candidate.push_back(calculate(min_result[i][i + k - 2],
                                      min_result[i + k][i + j],
                                      expression[i + k - 1]));
        candidate.push_back(calculate(min_result[i][i + k - 2],
                                      max_result[i + k][i + j],
                                      expression[i + k - 1]));
        candidate.push_back(calculate(max_result[i][i + k - 2],
                                      min_result[i + k][i + j],
                                      expression[i + k - 1]));
        candidate.push_back(calculate(max_result[i][i + k - 2],
                                      max_result[i + k][i + j],
                                      expression[i + k - 1]));

        sort(candidate.begin(), candidate.end());

        min_result[i][i + j] = min(min_result[i][i + j], candidate[0]);
        max_result[i][i + j] = max(max_result[i][i + j], candidate[3]);
      }
    }
  }

  cout << max_result[0][N - 1] << endl;

  return 0;
}

void fast_io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
}

void init_result() {
  for (int i = 0; i < N; i += 2) {
    max_result[i][i] = min_result[i][i] = expression[i] - '0';
  }
}

int calculate(int left, int right, char oper) {
  int result;

  switch (oper) {
    case '+':
      result = left + right;
      break;
    case '-':
      result = left - right;
      break;
    default:
      result = left * right;
      break;
  }

  return result;
}