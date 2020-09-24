

#include<iostream>

using namespace std;

int max(int a,int b){
    return a>b?a:b;
}

int sum(int a,int b){
    return a+b;
}
int *min(int a,int b){
    int *p=nullptr;
    if(a>b)
        p=&a;
    else   
        p=&b;
    return p;
}

void process(int i,int j,int (*p)(int a,int b)){
    cout<<p(i,j)<<endl;
}

int main(){
    int a=10;
    int b=20;
    process(a,b,max);

    int (*spf)(int a,int b)=sum;
    process(a,b,spf);

    int* out=min(a,b);
    cout<<*out<<endl;
    
}