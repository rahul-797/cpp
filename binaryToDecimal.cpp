#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int i=0,dec=0,n;
	cin >> n;
	while(n!=0){
		int rem=n%10;
		dec+=rem*pow(2,i);
		n/=10;
		i++;
	}
	cout << dec << endl;
	return 0;
}
