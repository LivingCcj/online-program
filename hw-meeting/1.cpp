#include<iostream>

#include<string>
#include<vector>

using namespace std;



vector<string> res; 

//"123"的全排列

void reCur(string &str,int k){

    if(k==str.size()){
        res.push_back(str);
        return;
    }
    for(int i=k;i<str.size();i++){
        swap(str[i],str[k]);
        reCur(str,k+1);
        swap(str[i],str[k]);
    }
}

int main(){
    string str;
    cin>>str;
    reCur(str,0);
    for(string str:res){
        cout<<str<<endl;
    }
}