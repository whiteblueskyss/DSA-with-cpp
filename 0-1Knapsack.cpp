#include <bits/stdc++.h>
#define ll long long int
#define F first
#define S second
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define endl "\n"
using namespace std;

void solve(){
	int n;
	cin>>n;
	vector<int>a(n);
	
	for(int i=0; i<n ;i++){
		cin>>a[i];
	}

	int ans = 0;
	int left=0, right = n-1;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			// cout<<"ok "<<j<< " "<<i<<endl<<endl;
			if(a[j]<a[i]){
				right = j-1;
				break;
			}
			right=n-1;
		}
		for(int j=i; j>=0; j--){
						// cout<<"ok "<<j<< " "<<i<<endl;

			if(a[j]<a[i]){
				left = j+1;
				break;
			}
			left=0;
		}
		//cout<<left <<" "<<right<<endl<<a[i]<<endl<<endl;
		ans = max(ans, a[i]*(right-left+1));
	}
	cout<<ans<<endl;
}

int main(){
    FAST
    int test=1, t=1;
    cin >> test;
    while(t<=test){

    	//cout<<"Case "<<t<<": ";
    	t++;
      solve();
    }
    return 0;
}