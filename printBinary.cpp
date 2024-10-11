#include <iostream>

#define fr(s, e) for (int i = s; i < e; i++)
using namespace std;

void generate(string s, int n) {
  if (n < 0) return;
  if (n == 0) {
    cout << s << endl;
    return;
  }
  if (s.back() == '1')
    generate(s + '0', n - 1);
  else {
    generate(s + '0', n - 1);
    generate(s + '1', n - 1);
  }
}

int main() {
  int n;
  cin >> n;

  generate("0", n - 1);
  generate("1", n - 1);

  cout << endl;
  return 0;
}
