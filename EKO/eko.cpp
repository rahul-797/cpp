#include <climits>
#include <iostream>
using namespace std;

bool isPossible(int arr[], int len, int req, int mid) {
  int sum = 0;
  for(int i = 0; i < len; i++){
  	if(arr[i] - mid > 0){
  		sum += (arr[i]-mid);
  	}
  }
  if(sum >= req){
  	return true;
  } else {
  	return false;
  }
}

int getHeight(int arr[], int len, int req) {
  int start = 0;
  int end = INT_MAX;
  int mid = start + (end - start) / 2;
  int answer = -1;
  while (start <= end) {
    if (!isPossible(arr, len, req, mid))
      end = mid - 1;
    else {
      answer = mid;
      start = mid + 1;
    }
    mid = start + (end - start) / 2;
  }
  return answer;
}

int main() {
  int n,req;
  cout << "Enter number of trees: ";
  cin >> n;
  cout << "Enter required wood in meters: ";
  cin >> req;
  cout << "Enter the tree lengths separated by space: ";
  int arr[n];
  for(int i = 0; i < n; i++){
  	cin >> arr[i];
  }
  int len = sizeof(arr) / sizeof(arr[0]);
  int height = getHeight(arr, len, req);
  cout << "Max height: " << height << endl;
  return 0;
}
