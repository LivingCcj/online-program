#include<iostream>
#include<string>
#include<string.h>

using namespace std;
typedef long long ll;
int mod=1000000007;
ll add(ll op1,ll op2){
    return (op1+op2)%mod;
}

ll miuns(ll op1,ll op2){
    return (op1-op2)%mod;
}

ll pow(ll base, ll n){
    ll res=1;
    ll factor=base;
    while(n>0){
        if(n&1) res=(res*factor)%mod;
        factor=(factor*factor)%mod;
        n>>=1;
    }
    return res;
}
ll mutil(ll op1, ll op2){
    ll res=(op1%mod)*(op2%mod);
    return res;
}

int main(){
    int n;
    cin>>n;
    string op1;
    string op2;
    string op;
    while(n--){
        cin>>op1>>op2>>op;
        ll t1=atol(op1.c_str());
        ll t2=atol(op2.c_str());
        ll res=0;
        if(op=="+"){
            res=add(t1,t2);
        }else if(op=="-"){
            res=miuns(t1,t2);
        }else if(op=="*"){
            res=mutil(t1,t2);
        }else {
            res=pow(t1,t2);
        }
        cout<<res<<endl;
    }
    return 0;
}