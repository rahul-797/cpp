#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n,bin=0,i=0;
	cin >> n;
	while(n!=0){
		if(n&1){
			bin+=pow(10,i);
		}
		n = n >> 1;
		i++;
	}
	cout << bin << endl;
	return 0;
}
