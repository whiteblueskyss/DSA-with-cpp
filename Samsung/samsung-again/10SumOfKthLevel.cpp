#include <iostream>
#include <vector>

using namespace std;


int main(){
    int n;
    cin>>n;

    string s, ans;
    cin>>s;

    int level = -1;

    int sum = 0;

    for(int i=0; i<s.size(); i++){
        if(s[i]=='('){
            level++;
        }
        else if(s[i]==')'){
            level--;
        }

        else if(level==n){
            ans = "";
            while(i<s.size() && s[i] != '(' && s[i]!=')'){
                ans.push_back(s[i]);
                i++;
            }
            i--;
            
            int x=0;
            
            for(int j=0; j<ans.size(); j++){
                x = x*10 + ans[j]-'0';
            }
            sum += x;
        }
    }

    cout<<sum<<endl;

    return 0;
}