#include<iostream>
#include<vector>

using namespace std;

int main(){
    int k,n;
    cin>>k>>n;
    int back=0;
    vector<int> record;
    int step=k;
    int num;
    while(n--){
        cin>>num;
        record.push_back(num);
    }
    for(int i=0;i<record.size();i++){
        if(step==0){
            cout<<"paradox"<<endl;
            break;
        }else{
            if(step>0){
                step=step-record[i];
                if(step<0) back++;
            }else{
                step=step+record[i];
                if(step>0) back++;
            }
        }
    }
    if(step>0){
        cout<<step<<" "<<back<<endl;
    }
    if(step<0){
        cout<<(-1*step)<<" "<<back<<endl;
    }
    
    return 0;
}