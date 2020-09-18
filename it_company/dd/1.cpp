#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<sstream>
using namespace std;

int main(){
    string n;
    getline(cin,n);

    int N=atoi(n.c_str());
    string str;
    getline(cin,str);

    int len=str.size();
    if(len<=N){
        reverse(str.begin(),str.end());
        cout<<str<<endl;
        return 0;
    }
    stack<char> data;
    ostringstream oss(ostringstream::ate);
    for(int i=0;i<str.size();i++){
        if(data.size()==N){
            while(!data.empty()){
                char tmp=data.top();
                data.pop();
                // oss<<tmp;
                cout<<tmp;
            }
        }
        data.push(str[i]);
        
        
    }
    while (!data.empty())
    {
        char tmp=data.top();
        data.pop();
        // oss<<tmp;
        cout<<tmp;
    }
    cout<<endl;

    // string res=oss.str();
    // cout<<res<<endl;
    return 0;
}