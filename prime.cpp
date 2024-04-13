#include <iostream>

using namespace std;

int main(){
	int n;
	cin >> n;
	int i = 2;
	bool prime = true;
	while(i < n){
		if(n % i == 0){
			prime = false;
			cout << "It is not prime" << "\n";
			break;
		}
		i += 1;
	}
	if(prime){
		cout << "It is prime" << "\n";	
	}
	return 0;
}
