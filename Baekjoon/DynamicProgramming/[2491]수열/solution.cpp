#include <iostream>
#include <vector>

using namespace std;

#define endl "\n"
#define MAX(X, Y) (X > Y ? X : Y)

vector<int> arr;
int N, tmp1, tmp2, res;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;

  arr = vector<int>(N + 1);

  for (int i = 1; i <= N; i++)
    cin >> arr[i];

  tmp1 = tmp2 = res = 1;

  for (int i = 1; i < N; i++) {
    if (arr[i] <= arr[i + 1])
      tmp1++;
    else
      tmp1 = 1;

    if (arr[i] >= arr[i + 1])
      tmp2++;
    else
      tmp2 = 1;

    int result = MAX(tmp1, tmp2);
    res = MAX(result, res);
  }

  cout << res << endl;

  return 0;
}