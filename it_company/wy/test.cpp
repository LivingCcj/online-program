#include<iostream>

using namespace std;
class A{

public:
    int a;
    // A(){
    //     cout<<" build A"<<endl;
    // };
    ~A(){
        cout<<" destructor A"<<endl;
    };
    void Dosomething(){
        cout<<"A is working"<<endl;
    };
    A & operator=(const A &rhs){
        a=rhs.a;
    };
    void A(const A &ca){
        a=ca.a;  
    }

};


int main(){
    
}