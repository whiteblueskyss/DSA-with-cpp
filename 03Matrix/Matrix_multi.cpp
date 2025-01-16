#include<iostream>
using namespace std;

int main(){
	int n, m, x, y, p=0,q=0;
	int a[3][4] = {{2, 4, 1, 2}, {8,4,3,6},{1,7,9,5}};
	int b[4][3] ={{1, 2, 3},{4, 5, 6},{7, 8, 9},{4, 5, 6}} ;
	int c[3][3];

	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			int sum = 0;
			for(int k=0; k<4; k++){
			 	sum += a[i][k]*b[k][j];
			}
		 	//cout << sum << endl;
			c[i][j]=sum;	
		}
	}
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			cout << c[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
