#include<iostream>

using namespace std;

int main()
{
    int arr[10] = {39, 2, 25, 26, 64, 36, 24, 22, 66, 77};
    /// print all sum array.
    int n =10;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            for(int k=i; k<=j; k++){
                cout << arr[k] << " ";
            }cout << endl;

        }
    }

    return 0;
}
