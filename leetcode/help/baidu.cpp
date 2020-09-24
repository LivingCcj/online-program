#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
using namespace std;

int main(){
    int T;
    cin>>T;
    int n,m;
    cin>>n>>m;
    unordered_map<int,int> data;
    int mark=m;
    int k;
    while(m--){
        cin>>k;
        int l,r;
        while(k--){
            cin>>l>>r;
            for(int i=l;r<=r;i++){
                data[i]++;
            }
        }
    }
    vector<int> res;
    auto iter=data.begin();
    while (iter !=data.end())
    {
        if(iter->second >= mark)
            res.push_back(iter->first);
    }

    sort(res.begin(),res.end(),less<int>());

    cout<<res.size()<<endl;
    for(int i=0;i<res.size()-1;i++){
        cout<<res[i]<<" ";
    }
    cout<<res[res.size()-1]<<endl;
    return 0;
}
