#include <bits/stdc++.h>
using namespace std;
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define F first
#define S second
#define PB push_back
#define PPB pop_back
#define MP make_pair
#define endl "\n"

ll recur(ll a, ll b){
    if(b==0){
        return 1;
    }
    ll res = recur(a,b/2);
    if(b&1){
        return a*res*res;
    }else{
        return res*res;

    }
}

ll iter(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b&1){
            ans = ans*a;
        }
        a = a*a;
        b >>= 1;
    }
    return ans;
}

ll multiply(ll a, ll b){
    ll ans =0;
    while(b){
        if(b&1){
            ans = ans+a;
        }
        a = a+a;
        b>>=1;
        // cout<<ans<< " "<<a<< " "<<b<<endl;

    }
    return ans;
}


int main(){
    ll a, b;
    cin>>a>>b;

    cout<<recur(a,b)<<endl;
    cout<<iter(a,b)<<endl;
    cout<<multiply(a,b)<<endl;
}