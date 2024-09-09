#include <iostream>
using namespace std;

int main(){
	int a[]={10, 35, 26, 23,64, 62};
	int n = sizeof(a)/sizeof(a[0]);
	int temp;
	for(int i=0; i<n; i++){
		for(int j=0; j<n-i-1; j++){
			if(a[j]>a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
	for(int i=0; i<n; i++){
		cout << a[i]<< " ";
	}
	cout << endl;
}