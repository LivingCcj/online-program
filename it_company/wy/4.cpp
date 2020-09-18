#include<iostream>

#include<vector>
#include<set>
#include<string>
#include<string.h>

using namespace std;

vector<string> split(string &str){
    const char *tmp=" ";
    char *p=strtok((char*)str.c_str(),tmp);
    vector<string> res;
    while(p){
        string tStr(p);
        res.push_back(tStr);
        // cout<<tStr<<endl;
        p=strtok(nullptr,tmp);
    }
    return res;
}

/**
 *
hello , ?
I am a boy
are you a girl ?
 **/
int main(){

    string str1;
    string str2;
    string str3;
    vector<string> V1;
    vector<string> V2;
    vector<string> V3;
    getline(cin,str1);
    getline(cin,str2);
    getline(cin,str3);
    
    V1=split(str1);
    V2=split(str2);
    V3=split(str3);
    // cout<<str1<<" "<<str2<<" "<<str3<<endl;
    
    set<string> hash;
    for(string str:V1){
        hash.insert(str);
    }
    vector<string> vv2;
    for(int i=0;i<V2.size();i++){
        if(hash.count(V2[i])<=0){
            vv2.push_back(V2[i]);
        }
    }

    vector<string> vv3;
    for(int i=0;i<V3.size();i++){
        if(hash.count(V3[i])<=0){
            vv3.push_back(V3[i]);
        }
    }

    int len1=vv2.size();
    int len2=vv3.size();
    vector<vector<int>> dp(len1+1,vector<int>(len2+1));

    for(int i=0;i<len1+1;i++){
        dp[i][0]=i;
    }
    for(int j=0;j<len2+1;j++){
        dp[0][j]=j;
    }

    for(int i=1;i<len1+1;i++){
        for(int j=1;j<len2+1;j++){
            if(vv2[i-1]==vv3[j-1]){
                dp[i][j]=dp[i-1][j-1];
            }else{

                dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
            }

        }
    }
    cout<<dp[len1][len2]<<endl;
    return 0;
}