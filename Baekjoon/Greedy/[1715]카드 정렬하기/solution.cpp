#include <iostream>
#include <queue>

using namespace std;

#define endl "\n"

priority_queue<int, vector<int>, greater<int>> pq;
int N, res, num;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> N;
  res = 0;

  for(int i = 0 ; i <N; i++){
    cin >> num;

    pq.push(num);
  }
  while (true){
    int lhs = pq.top();
    pq.pop();

    if(pq.empty()) break;

    int rhs = pq.top();
    pq.pop();

    res += lhs + rhs;

    pq.push(lhs + rhs);
  }

  cout << res << endl;
  
  return 0;
}