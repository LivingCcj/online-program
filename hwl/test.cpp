#include<iostream>

using namespace std;
struct  test
{
    int a;
    int b;
    char c[5];
};


int main(){
    test t;
    cout<<sizeof(t)<<endl;
}