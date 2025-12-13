#include<iostream>
#include <vector>
#include<map>

using namespace std;


int main(){
    int n,m,k;
    cin>>n>>m>>k;

    vector<vector<int>>v(n, vector<int>(m));

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>v[i][j];

    map<vector<int>, int>mp;

    for(int i=0; i<n; i++){
        int cnt = 0;
        for(int j=0; j<m; j++){
            if(v[i][j]==0){
                cnt++;
            }
        }

        if(cnt<=k && (k-cnt)%2==0){
            mp[v[i]]++;
        }
    }

    int ans =0 ;

    for(auto x : mp){
        ans = max(ans, x.second);
    }

    cout<<ans<<endl;

}