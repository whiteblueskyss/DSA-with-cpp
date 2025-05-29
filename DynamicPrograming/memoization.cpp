#include <bits/stdc++.h>
using namespace std;

int dp[100];
int total = 0;

int fib(int n){
    if(n<=1){
        return n;
    }
    if(dp[n]){
        // return dp[n];
    }
    total++;
    return dp[n]=fib(n-1)+fib(n-2);
}


int main(){
    dp[0] = 0;
    dp[1] = 1;

    cout<< fib(20)<<endl;
    cout<<total<<endl;
}