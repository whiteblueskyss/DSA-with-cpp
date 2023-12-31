//Author: whiteblueskyss
//Created Date:   2023-12-31 08:04:40
#include <bits/stdc++.h>
using namespace std;

int binarySearch(int ar[], int n, int key){
    int s = 0;
     int e = n;
     // cout<<e<<endl;
     // return;
    int mid;

    while(s<=e){
        mid = (s+e)/2;

        if(ar[mid]==key){
            return mid;
        }

        else if(ar[mid]>key){
            e = mid-1;
        }
        else{
            s = mid+1;
        }
    }

    return -1;
}


int main(){
    
    int ar[] = {2,4,5,7,8,33,56,78,97,100};
    int key = 4;
    int n = sizeof(ar)/sizeof(ar[0]);

    cout<<"idx of key is "<<binarySearch(ar,n,key)<<endl;
    
    return 0;
}