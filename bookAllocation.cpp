#include <iostream>
using namespace std;

bool isPossible(int arr[], int books, int students, int mid) {
  int studentCount = 1;
  int pageSum = 0;
  for (int i = 0; i < books; i++) {
    if (pageSum + arr[i] <= mid)
      pageSum += arr[i];
    else {
      studentCount++;
      if (studentCount > students || arr[i] > mid) {
        return false;
      }
      pageSum = arr[i];
    }
  }
  return true;
}

int allocateBooks(int arr[], int books, int students) {
  // Using BS, we find a number and then check if its a possible solution
  int start = arr[0];
  int end = 0;
  for (int i = 0; i < books; i++) {
    end += arr[i];
  }
  int mid = start + (end - start) / 2;
  int answer = 0;
  while (start <= end) {
    if (!isPossible(arr, books, students, mid))
      start = mid + 1;
    else {
      answer = mid;
      end = mid - 1;
    }
    mid = start + (end - start) / 2;
  }
  return answer;
}

int main() {
  int arr[10] = {20, 30, 30, 10, 15, 10, 20, 30, 30, 20};
  int books = sizeof(arr) / sizeof(arr[0]);
  int students = 6;
  int min = allocateBooks(arr, books, students);
  cout << min << endl;
  return 0;
}
