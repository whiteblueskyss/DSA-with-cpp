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

void solve(){
    ll n,x;
    cin>>n>>x;

    if(x<0){
        x*=-1ll;
        if(x<n){
            x = n-x-1;
            for(int i=0; i<x; i++){
                cout<<"*";
            }
            
            for(x ; x<n; x++){
                cout<<"-";
            }
            cout<<endl;
        }
        else{
            cout<<"-1"<<endl;
        }
    }
    else if(x==0){
        if(n%2==0){
            cout<<"*";
            for(int i=0; i<n/2-1; i++){
                cout<<"+";
            }
            for(int i=n/2-1; i<n-1; i++){
                cout<<"-";
            }
            cout<<endl;
            return;
        }
        if(n==1){
            cout<<"-"<<endl;
        }
        else{
            for(int i=0; i<n/2; i++){
                cout<<"+";
            }
            for(int i=n/2; i<n; i++){
                cout<<"-";
            }
            cout<<endl;
        }
    }
    else{

        if(x-1<=n){
            x-=n;
            x*=-1;
            for(int i=0; i<=x; i++){
                cout<<"*";
            }
            for(x ; x<n-1; x++){
                cout<<"+";
            }
            cout<<endl;
        }
        else{
            cout<<"-1"<<endl;
        }
    }
}

int main(){
    FAST
    int t=1;
    cin >> t;
    while(t--)solve();
    return 0;
}