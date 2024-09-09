
///Prmie factor using Sieve

#include<iostream>

using namespace std;

void spf(int n){
    int spf[n+10] = {0};

    for(int i=2; i<=n; i++)
        spf[i]= i;

    for(int i = 2; i<=n ; i++){
      if(spf[i] == i){
        for(int j= i*i; j<=n ; j+=i)
        {
            if(spf[j]==j)
            spf[j]=i;
            //cout << spf[j];
        }

      }
    }
    //for(int i=2; i<=n; i++)
   // cout << spf[i] << " ";

    //cout << endl << endl;

    while(n!=1){
        cout << spf[n] << " ";
        n=n/spf[n];
    }
}

int main()
{
    int n;
    cin >> n;
     spf(n);

    return 0;
}
