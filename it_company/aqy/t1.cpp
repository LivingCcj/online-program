

#include<iostream>

using namespace std;

int CountZero(int n){
    return n/5==0?0:n/5+CountZero(n/5);
}
int main(){
    int n;
    cin>>n;
    cout<<CountZero(n)<<endl;
}