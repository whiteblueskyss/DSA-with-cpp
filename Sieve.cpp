#include<iostream>
using namespace std;


int main(){
	int n;
	n = 100;
	int a[100];
	int b[100]={0};
	
	for(int i=2; i<100; i++){
		for(int j=i*i; j<n; j+=i){
			b[j]=1;
		}
	}

	for(int i=2; i<n; i++){
		if(!b[i]){
			cout << i<< " ";
		}
	}
	return 0;
}