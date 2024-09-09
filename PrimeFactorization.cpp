#include<iostream>
using namespace std;

void primeFactorization(){
	int n;
	cin >> n;
	int a[n];
	for(int i=0; i<=n; i++){
		a[i]=i;
	}

	for(int i=2; i<=n; i++){
		if(a[i]==i){
			for(int j=i*i; j<=n; j+=i){
				if(a[j]==j){
					a[j]=i;
				}
			}
		}
	}

	while(n!=1){
		cout << a[n] << " ";
		n=n/a[n];
	}
	cout << endl;
}

int main(){
	int t;
	cin >> t;
	while(t--){
		primeFactorization();
	}

	return 0;
}