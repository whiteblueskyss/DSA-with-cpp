#include <bits/stdc++.h>
using namespace std;

bool sorted(int a[], int n){
  if(n==1){
    return true;
  }
  bool ok =sorted(a+1,n-1);
  if(a[0]<=a[1] && ok){
    return true;
  }
  else{
    return false;
  }
}

int main(){
   int n=5;
  int a[]={3,4,5,6,7};
 
  bool ok = sorted(a,n);
  cout<<ok<<endl;
  return 0;
}