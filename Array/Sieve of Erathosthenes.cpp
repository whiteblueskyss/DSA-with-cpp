
///Sieve of Eratosthenes

#include<iostream>

using namespace std;

int erathosthenes(int n){
    int prime[n+2] = {0};
    for(int i=2; i<=n; i++){
            if(prime[i]==0){
         for(int j= i*i; j<=n ; j += i){
            prime[j]=1;

        }
            }
    }
    for(int i=2; i<=n; i++){
            //cout << prime[i]<< " ";
        if(prime[i] == 0){
            cout << i << " ";
        }
    }
    cout << endl;

    return 1;
}

int main()
{
    int n;
    cin >> n;
    erathosthenes(n);

    return 0;
}
