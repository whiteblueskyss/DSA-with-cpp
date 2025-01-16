/// Tower of Hanoi.
#include<iostream>

using namespace std;

void TowerofHanoi(int n, char src, char dest, char helper){

    if(n==0){
        return;
    }
    TowerofHanoi(n-1, src, helper, dest);
    cout << " Move " << src << " to " << dest << endl;

    TowerofHanoi(n-1, helper, dest, src );

}
int main()
{
    int n;
    cin >> n;
    TowerofHanoi(n, 'A', 'B', 'C');

    return 0;

}
