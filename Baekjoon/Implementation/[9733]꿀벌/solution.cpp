#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

#define endl "\n"

vector<string> work_list;
map<string, int> work;
string done;
int cnt;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  work_list = {"Re", "Pt", "Cc", "Ea", "Tb", "Cm", "Ex"};
  cnt = 0;

  while (cin >> done) {
    cnt++;
    work[done]++;
  }

  cout << fixed;
  cout.precision(2);

  for (int i = 0; i < 7; i++) {
    cout << work_list[i] << " " << work[work_list[i]] << " " << (double)work[work_list[i]] / cnt << endl;
  }
  cout << "Total " << cnt << " " << 1.00 << endl;

  return 0;
}