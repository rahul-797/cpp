#include <iostream>
using namespace std;

class Stack {
 public:
  int* arr;
  int top;
  int size;

  Stack(int size) {
    this->arr = new int[size];
    this->size = size;
    top = -1;
  }

  void push(int element) {
    if (size - top <= 1) {
      cout << "stack overflow" << endl;
      return;
    }
    arr[top + 1] = element;
    top += 1;
  }

  void pop() {
    if (top == -1) {
      cout << "stack underflow" << endl;
      return;
    }
    arr[top] = 0;
    top -= 1;
  }

  int peek() {
    if (top == -1) {
      cout << "Stack is empty" << endl;
      return -1;
    }
    return arr[top];
  }

  void print() {
    for (int i = 0; i < size; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
};

int main() {
  Stack* s = new Stack(4);
  s->push(1);
  s->push(2);
  s->push(3);
  s->push(4);
  s->print();

  s->pop();
  s->pop();
  s->pop();
  s->pop();
  s->print();

  s->push(1);
  s->push(2);
  s->push(3);
  s->push(4);
  cout << s->peek() << endl;
  return 0;
}
