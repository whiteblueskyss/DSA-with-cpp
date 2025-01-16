#include <bits/stdc++.h>
using namespace std;

void fn(string s){
	int len = s.size();
	if(len==0){
		return;	
	}

	if(s[0]=='p' && s[1]=='i'){
		cout << "3.1416";
		fn(s.substr(2));
	}
	else{
		cout <<s[0];
		fn(s.substr(1));
	}
}

int main(){
	string s;
	cin >> s;
	fn(s);
}