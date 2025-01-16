#include<iostream>
using namespace std;

int main()
{
	int a[]= { 3, 34, 64, 64, 23, 53, 53};
	int n  = 7;
	int temp;
	cout << n << endl;
	for(int i=0; i<n-1; i++){
		for(int j=i+1; j<n; j++){
			if(a[i]>a[j]){
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}

	for(int i=0; i<n; i++){
		cout<< a[i] << " ";
	}

	cout << endl;

	return 0;
}