#include "solution.h"

int main() {
  vector<string> musicinfos;

  cout << solution("ABCDEFG", musicinfos = {"12:00,12:14,HELLO,CDEFGAB", "13:00,13:05,WORLD,ABCDEF"}) << endl;

  cout << solution("CC#BCC#BCC#BCC#B", musicinfos = {"03:00,03:30,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B"}) << endl;

  cout << solution("ABC", musicinfos = {"12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF"}) << endl;

  return 0;
}