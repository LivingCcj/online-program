#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<string.h>
#include<ostream>

using namespace std;

int main(){
    vector<int> data;
    string str;
    while(1){
        cin>>str;
        if(str=="#"){
            break;
        }else{
            data.push_back(atoi(str.c_str()));
        }
        
    }
    int sum;
    cin>>sum;
    int size=data.size();
    int i=0;
    int j=size-1;
    vector<vector<int>> res;
    vector<int> vtmp;
    while (i<j)
    {
        if(data[i]>sum){
            break;
        }

        int tmp=data[i]+data[j];
        if(tmp>sum){
            j--;
        }else if(tmp< sum){
            i++;
        }else{
            vtmp.push_back(data[i]);
            vtmp.push_back(data[j]);
            i++;
            j--;
            res.push_back(vtmp);
            vtmp.clear();
        }
        if(i<(size-1) && data[i]==data[i+1] && (sum%2==0  && data[i]==sum/2)){
            vtmp.push_back(data[i]);
            vtmp.push_back(data[i+1]);
            res.push_back(vtmp);
            vtmp.clear();
        }
        while(i<(size-1) && (data[i]==data[i+1])) {
            i++;
            continue;
        }
        while(j>0 && (data[j]==data[j-1])) {
            j--;
            continue;
        }
        if(i>size-1 || j<0 || j<i){
            break;
        }
        
    }
    string out;
    if(res.size()>0){
        for(int i=0;i<res.size();i++){
            out.append("(");
            out.append(to_string(res[i][0])).append(",").append(to_string(res[i][1]));
            out.append("),");
        }
        out=out.substr(0,out.size()-1);
        cout<<out<<endl;
    }else{
        cout<<"NULL"<<endl;
    }
    
    return 0;
    
}
