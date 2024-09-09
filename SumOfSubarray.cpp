#include<iostream>
using namespace std;

int main(){
	int a2[10], a[] = { 3, 6, 2, 6, 2, 6, 7};
	int sum = 16, i, j, n = 7,temp;

	a2[0]=0;

	for(i=1; i<=n; i++){
		a2[i]=a[i]+a2[i-1];
	}

	for(i=0 ; i<n; i++){
		temp = a2[i];
		for(j = i+1 ; j<=n && temp<sum; j++){
			temp = a2[j]-a2[i];
			if(temp==sum)
				break;
		}
		if(temp == sum)
				break;
	}

	cout << a2[j]-a2[i] << endl;

	cout << i+2 << " " << j+1 << endl;

	return 0;
}
