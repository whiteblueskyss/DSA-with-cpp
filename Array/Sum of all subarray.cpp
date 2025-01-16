#include<iostream>
#include<climits>

using namespace std;

int main()
{
    int arr[10] = { 30, -39, 22, -55 ,24, 63, 23, -64, 2, 6};
    int sumarr[10+1], sum , n =10, i, j, x, y, k, mxsum=arr[0];
    sumarr[0]=0;

    for(i=1; i<=n; i++){
        sumarr[i]=sumarr[i-1]+arr[i-1];
    }

    for(i=1; i<=n; i++){
        for(j=0; j<i; j++){
            sum = sumarr[i]-sumarr[j];
            mxsum = max(sum, mxsum);
        }
    }
    cout << mxsum <<endl;


    /// another method. kadane's algo.
    int currentsum=0;

    for(i=1; i<=n; i++)
    {
        currentsum+=arr[i];

        if(currentsum<0)
            currentsum = 0;
        mxsum = max(currentsum, mxsum);
    }
    cout << mxsum << endl;

    return 0;
}
