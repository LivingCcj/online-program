#include<iostream>
#include<stdio.h>

using namespace std;

double cal(int A,int B,int C,int D){
    double resC=0.0f;
    double resB=0.0f;
    resC=1/3.0*A*C*C*C+1/2.0*C*C+B*C;
    resB=1/3.0*A*D*D*D+1/2.0*D*D+B*D;
    double res=resC-resB;
    return res<0.0?-res:res;
}
int main(){
    int n;
    cin>>n;
    int A,B,C,D;
    while(n--){
        cin>>A>>B>>C>>D;
        double res=cal(A,B,C,D);
        printf("%.8f\n",res);
    }

}
