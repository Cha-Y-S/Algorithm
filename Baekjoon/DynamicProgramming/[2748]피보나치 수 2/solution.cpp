#include <iostream>
#include <vector>

using namespace std;

int main() {
  int n;
  vector<long long> fibo;

  cin >> n;

  fibo.push_back(1);
  fibo.push_back(1);

  for (int i = 2; i < n; i++) {
    fibo.push_back(fibo[i - 1] + fibo[i - 2]);
  }

  cout << fibo[n - 1] << endl;

  return 0;
}