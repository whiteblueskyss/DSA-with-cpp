#include<iostream>
using namespace std;

int main(){
	int a[] = {10, 20, 25, 30, 35, 36, 37, 66};
	int n = 8;
	int key = 30;
	int indx1=0, indx2=n-1, mid=n/2;

	while(indx1<=indx2){
		//cout << mid << endl;
			if(a[mid]==key){
			break;
		}
		else if(a[mid]>key){
			indx2 = mid-1;
		}
		else if(a[mid]<key){
			indx1 = mid+1;
		}
		mid = (indx1+indx2)/2;
	}
	cout << mid << endl;

	return 0;

}
