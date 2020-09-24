#include<iostream>

using namespace  std;


int gcd(int a,int b){
    return b==0 ? a: gcd(b,a%b);
}
int lcm(int a,int b){
    int factor=gdb(a,b);
    return (a/factor)*b;
}
int main(){
    
}