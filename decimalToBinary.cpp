#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n,i=0;
	long double bin=0;
	cin >> n;
	if(n>=0){
		while(n!=0){
			bin+=(n&1)*pow(10,i);
			n = n >> 1;
			i++;
		}
	}
	else {
		n=(-n);
		unsigned int ni = ~n;
		while(ni!=0){
			bin+=(ni&1)*pow(10,i);
			ni = ni >> 1;
			i++;
		}
	}
	cout << bin << endl;
	return 0;
}
