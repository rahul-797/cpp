#include <iostream>

using namespace std;

int main() {
	int n, i = 0;
	cin >> n;
	int even = 0;
	int odd = 0;
	while(i<=n){
		if(i%2 == 0){
			even = even + i;
		} else {
			odd = odd + i;
		}
		i = i+1;
	}
	cout << "Even sum: " << even << endl;
	cout << "Odd sum: " << odd << endl;
	return 0;
}
