#include<iostream>

using namespace std;

int clearbit(int a, int b){
    int mask = ~(1<<b);
    return (a & mask);
}
int main()

{
    int a, b;
    cin >> a >> b;
    cout << clearbit(a,b);
    return 0;
}
