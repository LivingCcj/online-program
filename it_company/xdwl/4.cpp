#include<iostream>
#include<cmath>
using namespace std;


int main(){
    long long d,s;
    cin>>d>>s;
    
    long long max;
    long long pw=pow(d,2);
    max=floor(sqrt(s/pw))+1;
    bool flag=false;
    long long  up=floor(sqrt(max))+1;
    for(long long  i=up;i>=up/2;i--){
        for(long long  j=0;j<=up/2;j++){
            long long tmp=d*d*(i*i-j*j);
            if(tmp==s){
                cout<<i<<" "<<j<<endl;
                flag=true;
                break;
            }
        }
        if(flag){
            break;
        }
    } 
    if(!flag){
        cout<<0<<" "<<0<<endl;
    }
    return 0;
    
}