#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int cmp(int x,int y){
    return x>y;
}
int main(){
    int n;
    cin>>n;
    vector<int> data;
    int sum=0;
    int in1,in2;
    while(n--){
        cin>>in1>>in2;
        if(in2==1){
            data.push_back(in1);
        }else{
            sum+=in1;
        }
    }
    sort(data.begin(),data.end(),cmp);

    for_each(data.begin(),data.end(),[](int x){cout<<x<<endl;});
    for(int i=0;i<data.size();i++){
        if((sum*2)<data[i]){
            sum+=data[i];
        }else{
            sum=sum*2;
        }
    }
    cout<<sum<<endl;
}
