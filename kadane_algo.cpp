#include<iostream>
using namespace std;

int kadane(int a[], int n){
	int sum = INT_MIN;
	int csum=0;
	for(int i=0; i<n; i++){
		csum += a[i];
		if(csum <0){
			csum = 0;
		}
		sum = max(sum, csum);
	}
	return sum;
}

int main(){
	int a[] = {3, 2, -2, -24, 5, -6 , 9, 6};
	int n = sizeof(a)/sizeof(a[0]);

	int csum=0;
	int sum = kadane(a, n);
	int totalsum= 0;

	for(int i=0; i<n; i++){
		totalsum += a[i];
		a[i] = -a[i];
	}

	totalsum = max(totalsum+kadane(a, n), sum);
	cout << totalsum << endl;


	return 0;
}
