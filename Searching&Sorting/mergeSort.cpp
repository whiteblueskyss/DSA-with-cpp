//Author: whiteblueskyss
//Created Date:   2024-01-05 08:19:50
//Last Modified time: 2024-01-05 09:01:07
#include <bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int cnt = 0;

int a[N];

void merge(int l, int r, int mid){
    int lsz = mid-l+1, rsz = r-mid;
    int L[lsz+1], R[rsz+1];
    
    for(int i=0; i<lsz; i++){
        L[i] = a[i+l];
    }
    for(int i=0; i<rsz; i++){
        R[i] = a[i+mid+1];
    }

    int lidx = 0;
    int ridx = 0;
    L[lsz] = R[rsz] = INT_MAX;

    for(int i=l; i<=r; i++){
        if(L[lidx]<R[ridx]){
            a[i] = L[lidx++];
        }
        else{
            a[i] = R[ridx++];
        }
    }
}

void mergeSort(int l, int r){
    if(l==r)
        return;
    int mid = (l+r)/2;
    mergeSort(l,mid);
    mergeSort(mid+1,r);
    merge(l,r,mid);

    // cout<<cnt++<<endl;
    // for(int i=0; i<8; i++){
    //     cout<<a[i]<< " ";
    // }cout<<endl;
}

int main(){
    int n;
    cin>>n;

    for(int i=0; i<n; i++){
        cin>>a[i];
    }

    mergeSort(0,n-1);

    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }cout<<endl;

    return 0;
}