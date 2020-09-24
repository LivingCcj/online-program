#include<iostream>

using namespace std;


int res=0;
static int M;
static int count=0;
void recr(int prev,int prevv,int num){
    if(num<0){
        return ;
    }
    if(num==0){
        res++;
    }else{
        for(int i=1;i<=M;i++){
            if(i==prev || i== prevv ){
                continue;
            }else{
                count++;
                recr(prevv,i,num-i);
            }
        }
    }
}   
int main(){
    int n,m;
    cin>>n>>m;
    int prev=0;
    int prevv=0;
    M=m;
    cout<<M<<n<<endl;
    recr(prev,prevv,n);
    cout<<res<<endl;
    cout<<count<<endl;

}