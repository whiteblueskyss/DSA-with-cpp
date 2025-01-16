#include<iostream>
using namespace std;

int main(){
	int a[] = {5, 3 ,5, 2, 7, 8, 1};
	int n = sizeof(a)/sizeof(a[0]);
	int temp;
	for(int i=1; i<n; i++){
		temp = i;
		while(a[temp]<a[temp-1] && temp>0){
			swap(a[temp], a[temp-1]);
			temp--;
		}
	}
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << endl;
	}

	return 0;
}