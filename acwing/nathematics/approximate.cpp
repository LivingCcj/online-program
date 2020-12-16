/*
 * @Description: 求约数 ：https://www.acwing.com/problem/content/871/
 * 
 * 时间复杂度是sqrt(n)
 * @Author: ccj
 * @Date: 2020-12-16 10:23:39
 * @LastEditTime: 2020-12-16 10:27:49
 * @LastEditors:  
 */


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<int> get_diviors(int x){
    vector<int> res;
    for(int i=1;i<=x/i;i++){
        if(x%i==0){
            res.push_back(i);
            //mark: i==n/i时，只保留一个i。 
            if(i!=x/i) res.push_back(x/i);  
        }
    }
    sort(res.begin(),res.end());
    return res;
}

int main(){
    int n,m;
    cin>>n;
    while(n--){
        cin>>m;
        vector<int> res=get_diviors(m);
        for(auto i:res) cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}