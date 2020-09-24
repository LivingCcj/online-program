
#include<iostream>

using namespace std;

int func(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;

    }
    if(n==2){
        return 2;
    }
    if(n==3){
        return 4;
    }
    return func(n-1)+func(n-2)+func(n-3);
}
int main(){
    int n;
    cout<<func(10);
}