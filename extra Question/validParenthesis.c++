#include<iostream>
using namespace std;
#include<stack>

stack<char>s;
bool valid_Parenthesis(string str){
    for (int i = 0; i < str.length(); i++){
        if(str[i]=='('||str[i]=='['||str[i]=='{'){
            s.push(str[i]);
        }
        
        else {
            if (s.empty()||str[i] ==')'&&s.top()!='('||str[i]==']'&&s.top()!='['||str[i]=='}'&&s.top()!='{'){
                return false;
            }  
                s.pop();
            
        }

    }

    return s.empty();
}
int main(){

    string str = "({})";

    cout<<valid_Parenthesis(str);

    return 0;
}