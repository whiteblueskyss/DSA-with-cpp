#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <climits>
#include <cstring>
#include <utility>
#include <map>
#include <queue>

using namespace std;

int distance(pair<int,int>p, pair<int,int>q){
    return abs(p.first-q.first)+abs(p.second-q.second);
}


void solve(){
    int n;
    cin>>n;

    int sx,sy,dx,dy;
    cin>>sx>>sy>>dx>>dy;

    vector<pair<int,int>>nodes;

    nodes.push_back({sx,sy});
    nodes.push_back({dx,dy});

    map<pair<int,int>, vector<pair<pair<int,int>,int>>>mp;

    for(int i=0; i<n; i++){
        int a,b,c,d,e;
        cin>>a>>b>>c>>d>>e;

        mp[{a,b}].push_back({{c,d},e});
        mp[{c,d}].push_back({{a,b},e});

        nodes.push_back({a,b});
        nodes.push_back({c,d});
    }

    map<pair<int,int>,int>dis;
  
    for(auto x : nodes){
        dis[x] = INT_MAX;
    }

    priority_queue<pair<int, pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int, pair<int,int>>>>pq;

    pq.push({0, nodes[0]});

    dis[nodes[0]] = 0;

    while(!pq.empty()){

        pair<int,int> cur = pq.top().second;
        pq.pop();

        for(auto x : nodes){
            int d = distance(x,cur);

            if(dis[cur] + d <dis[x]){
                dis[x] = dis[cur]+d;
                pq.push({dis[x], x});
            }
        }

        for(auto x : mp[cur]){

            pair<int,int>temp = x.first;
            int cost = x.second;

            if(dis[cur] + cost < dis[temp] ){
                dis[temp] = dis[cur] + cost;
                pq.push({dis[temp], temp});
            }
        }
    }

    cout<<dis[nodes[1]]<<endl;

}


int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}