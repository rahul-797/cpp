#include <iostream>
#include <string>
using namespace std;

string s = "";

string sayNum(int num) {
  if (num == 0) return "";
  string say = "";
  switch (num % 10) {
    case 0:
      say = "Zero";
      break;
    case 1:
      say = "One";
      break;
    case 2:
      say = "Two";
      break;
    case 3:
      say = "Three";
      break;
    case 4:
      say = "Four";
      break;
    case 5:
      say = "Five";
      break;
    case 6:
      say = "Six";
      break;
    case 7:
      say = "Seven";
      break;
    case 8:
      say = "Eight";
      break;
    case 9:
      say = "Nine";
      break;
  }
  s = say + " " + s;
  return sayNum(num / 10);
}

int main() {
  int num;
  cin >> num;
  sayNum(num);
  cout << s << endl;
  return 0;
}
