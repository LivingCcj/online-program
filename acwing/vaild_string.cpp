#include<bits/stdc++.h>


using namespace std;

bool isVaild(string &str){
    stack<char> data;
    bool res=true;

    char tmp=' ';
    for(int i=0;i<str.size();i++){
        if(str[i]=='[' || str[i]=='{' || str[i] == '(')
        {
            data.push(str[i]);
            continue;
        }
        if(!data.empty()){
            tmp=data.top();
        }
        if(tmp =='[' && str[i]==']'){
            data.pop();
            if(data.empty()){
                return false;
            }
            continue;
        }

        if(tmp =='(' && str[i]==')'){
            data.pop();
            if(data.empty()){
                return false;
            }
            continue;
        }
        if(tmp =='{' && str[i]=='}'){
            data.pop();
            if(data.empty()){
                return false;
            }
            continue;
        }
    }
    if(data.empty()){
        return true;
    }else{
        return false;
    }
}

int main(){


    string str;
    while (cin>>str)
    {
        cout<<isVaild(str)<<endl;
    }

    return 0;
    

}