#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#define endl "\n"

vector<string> p1;
vector<string> p2;
vector<string> res;
int N, M;

void get_res(vector<string> v1, vector<string> v2);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N >> M;

  p1 = vector<string>(N);
  p2 = vector<string>(M);

  for (int i = 0; i < N; i++)
    cin >> p1[i];

  for (int i = 0; i < M; i++)
    cin >> p2[i];

  sort(p1.begin(), p1.end());
  sort(p2.begin(), p2.end());

  if (N < M)
    get_res(p1, p2);
  else
    get_res(p2, p1);

  cout << res.size() << endl;

  for (int i = 0; i < res.size(); i++)
    cout << res[i] << endl;

  return 0;
}

void get_res(vector<string> v1, vector<string> v2) {
  int result = 0;
  for (int i = 0; i < v1.size(); i++) {
    if (binary_search(v2.begin(), v2.end(), v1[i])) {
      res.push_back(v1[i]);
    }
  }
}