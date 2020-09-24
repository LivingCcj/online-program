
#include<iostream>
#include<mutex>
#include<thread>
#include<unistd.h>
#include<condition_variable>

using namespace std;

condition_variable cv;
mutex mt;
bool flag=true;
int i=1;
void fun1(int s){
    while(i<100){
        usleep(1000);
        unique_lock<mutex> lck(mt);
        cv.wait(lck,[]{return flag;});
        cout<<s<<": "<<i<<endl;
        i+=1;
        flag=false;
        cv.notify_one();
    }
}

void fun2(int s){
    while(i<100){
        unique_lock<mutex> lck(mt);
        cv.wait(lck,[]{return !flag;});
        cout<<s<<": "<<i<<endl;
        i+=1;
        flag=true;
        cv.notify_one();
    }
}


int main(){
    string s1="A: ";
    string s2="B: ";
    thread t1(fun1,1);
    thread t2(fun2,2);
    cout<<t1.get_id()<<"  "<<t2.get_id()<<endl;
    t1.join();
    t2.join();
    
    // return 0;
    // system("pause");
}



