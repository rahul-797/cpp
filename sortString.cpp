#include <string.h>

#include <iostream>
using namespace std;

int main() {
  char *names[] = {"rahul", "amit", "shubham"};
  cout << strlen(names[1]) << endl;
  for (int i = 0; i < 3; i++) {
  }
  /* for (auto i : names) { */
  /*   cout << i << endl; */
  /* } */
  cout << endl;
  return 0;
}
