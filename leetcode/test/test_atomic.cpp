#include<iostream>
#include<thread>
#include<atomic>
#include<unistd.h>
using namespace std;

// atomic<int> a(0);
atomic_int a(0);
void count(){
    a++;
    cout<<a<<endl;
}

int main(){

    thread t[10];
    for(int i=0;i<10;i++){
        t[i]= thread(count);
    }
    for(int i=0;i<10;i++){
        t[i].join();
    }

    
}