#include<bits/stdc++.h>
using namespace std;

int main(){
	int a[] = {3, 5 , 2, 6, 67, 23, 2 , 5};
	int n = sizeof(a)/sizeof(a[0]);
	int N = 1e5+2;
	int idx[N];

	for(int i=0; i<N; i++){
		idx[i]=-1;
	}

	int minidx = INT_MAX;
	//cout << minidx << endl;

	for(int i=0; i<n; i++){
		if(idx[a[i]] != -1){
			minidx = min(minidx, idx[a[i]]);			
		}
		else{
			idx[a[i]] = i;
		}

	}
	if( minidx==INT_MAX){
		cout << "-1 " << endl;
	}
	else{
		cout << minidx+1 << endl;
	}

	return 0;
}