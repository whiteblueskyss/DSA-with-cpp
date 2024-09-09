#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define F first
#define S second
#define endl "\n"

void solve(){
	ll n=100;
	//cin>>n;
	
	vector<bool>pr(n+1,true);
	pr[0]=false;
	pr[1]=false;

	for(ll i=2; i*i<=n; i++){
		if(pr[i]==false){
			continue;
		}
		for(ll j=i*i; j<=n; j+=i){
			pr[j]=false;
		}
	}
	ll cnt=0;

	for(int i=2; i<=n; i++){
		if(pr[i]){
			cnt++;
			cout<<i<<" ";
		}
	}
	cout<<endl<<endl<<cnt<<endl;

}

int main(){
    FAST
    int test=1;
    //cin >> test;
    while(test--){
        solve();
    }
    return 0;
}