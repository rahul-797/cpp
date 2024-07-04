#include <algorithm>
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

void popMiddle(Stack*& s, int count, int top) {
  if (count == top / 2) {
    s->pop();
    return;
  }
  int val = s->peek();
  s->pop();

  popMiddle(s, count + 1, top);

  s->push(val);
}

int main() {
  Stack* s = new Stack(8);
  s->push(1);
  s->push(2);
  s->pop();
  s->push(2);
  s->push(3);
  s->push(4);
  s->push(5);
  s->push(6);
  s->push(7);
  s->push(8);

  s->print();
  int count = 0;
  popMiddle(s, count, s->top);
  cout << "After popping middle: " << endl;
  s->print();
  return 0;
}
