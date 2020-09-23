#include<bits/stdc++.h>

using namespace std;

vector<int> countBits(int num) {
    vector<int> res;
    for(int i=0;i<=num;i++){
        int tmp=i;
        int count=0;
        while(tmp){
            if(tmp&1) count++;
            tmp>>=1;
        }
        res.push_back(count);
        // cout<<count<<endl;
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    vector<int> res=countBits(n);
    ostringstream oss;
    oss<<'[';
    for(int i=0;i<res.size();i++){
        oss<<res[i];
        
        if(i!=(res.size()-1)){
            oss<<',';
        }
    }
    oss<<']';
    cout<<oss.str()<<endl;
    return 0;
}