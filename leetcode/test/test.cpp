
#include<iostream>
#include<string>
#include<sstream>
#include<stdlib.h>
#include<algorithm>
#include<cstring>
#include <string.h>
using namespace std;



mutex mt;
class Singleton
{
public:
    static Singleton* getInstance();
private:
    Singleton(){};   //私有构造函数
    Singleton(const Singleton&){} =delete //明确拒绝
    Singleton operator=(const Singleton &) = delete //明确拒绝

    static Singleton* m_instance;

};

Singleton* Singleton::m_instance=NULL;

//饿汉式，线程安全版本
Singleton* Singleton::getInstance(){
    if(m_instance==NULL){
        mt.lock();
        if(m_instance==NULL){
            m_instance=new Singleton();
        }
        mt.unlock();
    }
    return m_instance;
}

//饿汉式，线程不安全版本
Singleton* Singleton::getInstance(){
    if(m_instance===NULL){
        m_instance=new Singleton();
    }
    return m_instance;
}

//引用一个指向本地local static的对象
//声明：
static Singleton& getlnstance();
Singleton& Singleton::getInstance(){
    static Singleton instance;
    return instance;
}

class test{
public:
    int A;
    int B;
public:
    test(int a,int b):A(a),B(b){};
};

int main(){
    int n=10;
    stringstream ss;
    ss<<n;
    string str;
    ss>>str;
    ss.clear();
    cout<<str<<endl;
    string zero="0";
    cout<<atoi(zero.c_str())<<endl;

    char ch ='0'+30;
    cout<<ch<<endl;
    ss<<100;
    ss>>str;
    cout<<str<<endl;



    memcpy();
    vector<int> data(3);
    for_each(begin(data),end(data),[](int x){cout<<x<<"  ";});
    test t(1,2);
    cout<<t.A<<" "<< t.B<<endl; 
    test *t1;
    t1=&t;
    cout<<t1->A<<" "<<t1->B<<endl;

    char buffer[256];
    char name[30]="Cuichaojie";

    snprintf(buffer,sizeof(buffer),"Name:%s age is %ld",name,strlen(name));

    cout<<buffer<<endl;
    cout<<"size:"<<sizeof(buffer)<<endl;
    char name1[20]="hhhhh hhhhh";
    char name2[10]="en3";
    strncpy(name1,name2,2);
    cout<<name1<< "  size:"<<strlen(name1)<<endl;
}