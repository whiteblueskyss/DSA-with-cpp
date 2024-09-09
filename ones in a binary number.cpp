#include<iostream>
using namespace std;

int ones(int n){

	int cnt = 0;
	while(n){
		cnt ++;
		n=n&(n-1);
	}
	return cnt;
}
int main(){
	
	int n = 19;
	cout << ones(n);

	return 0;
}
