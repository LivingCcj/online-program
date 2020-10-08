#include<iostream>

using namespace std;
class A{
public:
    int num;
    int str;
    int str2;
    char ch;
    static int sta;
    string strs;
    A (){num=5;}
    A(const A &b){};
    virtual void func(){
        cout<<"funcA"<<endl;
    }
};

class B: public A{
public:
    virtual void func(){
        cout<<"funcB"<<endl;
    }
};
void show(A a){
    cout<<a.num<<endl;
}

int main(){
    
    B b;
    cout<<"b:"<<sizeof(b)<<endl;
    b.func();
    A* a=&b;
    cout<<"A:"<<sizeof(a)<<endl;
    a->func();
    A a1;
    show(a1);
    return 0;
}

