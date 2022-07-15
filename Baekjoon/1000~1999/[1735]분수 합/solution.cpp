#include <iostream>

using namespace std;

#define endl "\n"

int getGCD(int a, int b);
int getLCM(int a, int b);

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int a_num, a_denum, b_num, b_denum;
  int num, denum;

  cin >> a_num >> a_denum >> b_num >> b_denum;

  int lcm = getLCM(a_denum, b_denum);

  denum = lcm;

  num = (a_num * (lcm / a_denum)) + (b_num * (lcm / b_denum));

  int gcd = getGCD(num, denum);

  cout << num / gcd << " " << denum / gcd << endl;

  return 0;
}

int getGCD(int a, int b) {
  while (a % b != 0) {
    int temp = a;
    a = b;
    b = temp % b;
  }
  return b;
}

int getLCM(int a, int b) {
  return a * b / getGCD(a, b);
}