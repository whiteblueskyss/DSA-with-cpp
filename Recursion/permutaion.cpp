#include<bits/stdc++.h>
using namespace std;

int a[3] = {1,2,3};
vector<int>v;
int n = 3;
bool b[3] = {false, false, false};

void search(){
    if(v.size()==n){
        for(auto j : v){
            cout<<j<< " ";
        }cout<<endl;
    }
    else{
        for(int i=0; i<n; i++){
            if(b[i])
                continue;
            b[i] = true;
            v.push_back(a[i]);

            // for(auto j : v){
            //     cout<<j<<" ";
            // }cout<<endl;
            
            search();

            // for(auto j : v){
            //     cout<<j<<" ";
            // }cout<<endl;

            
            b[i] = false;
            v.pop_back();
        }
    }
}



int main(){
    search();
}
