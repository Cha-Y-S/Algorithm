#include <string>
#include <vector>

using namespace std;

int gcd(int n, int m);

vector<int> solution(int n, int m) {
  vector<int> answer;

  answer.push_back(gcd(n, m));

  answer.push_back((n * m) / gcd(n, m));

  return answer;
}

int gcd(int n, int m) {
  if (m == 0) return n;
  return gcd(m, n % m);
}