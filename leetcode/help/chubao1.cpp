#include<iostream>

using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    int l,time;
    int ans=0;
    for(int i=0;i<m;i++){
        cin>>l>>time;
        int space=l/time*3.6;
        if(space<=n){
            ans=n;
        }else{
            while(space>n){
                time+=time;
                space=l/time*3.6;
            }
            ans=space;
        }
    }
    cout<<ans<<endl;
}