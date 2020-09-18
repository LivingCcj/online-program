#include<iostream>
#include<stack>

using namespace std;

bool check(string &str){
    stack<char> data;
    for(int i=0;i<str.size();i++){
        
        char tmp2=str[i];
        if(data.empty()){
            data.push(tmp2);
            continue;
        }
        char tmp1=data.top();
        if((tmp1=='(') && (tmp2==')')){
            data.pop();
            continue;
        }
        if((tmp1=='{') && (tmp2=='}')){
            data.pop();
            continue;
        }
        if((tmp1=='[') && (tmp2==']')){
            data.pop();
            continue;
        }
        else{
            data.push(tmp2);
        }
    }
    return data.empty();
}

int main(){
    string str;
    cin>>str;
    if(str.size()==0){
        cout<<"True"<<endl;
        return 0;
    }
    if(check(str)){
        cout<<"True"<<endl;
    }else{
        cout<<"False"<<endl;
    }
    return 0;
}