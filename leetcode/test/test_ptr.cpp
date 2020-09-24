#include<iostream>


using namespace std;

class A{
public:
    int a;
    virtual void    func1(){
        cout<<"A::func1"<<endl;

    }
};



class B :public A{ 
public:
    int b;
    virtual void   func1(){
        cout<<"B::func1"<<endl;

    }
    virtual void funcB(){
        cout<<"B:funcB"<<endl;
    }
};


int main(){
    A *pa=new B();
    pa->func1();
    A *pb=dynamic_cast<A*>(pa);
    pb->func1();
    // pb->funcB();
    if(pa==pb){
        cout<<"pa==pb"<<endl;
    }else{
        cout<<"pa!=pb"<<endl;
    }
}