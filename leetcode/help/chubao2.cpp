

#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> data(n);
    for(int i=0;i<n;i++) cin>>data[i];

    sort(data.begin(),data.end());
    for_each(data.begin(),data.end(),[](int x){cout<<x<<" "<<endl;});

    // for(int i=0;i<)
}