#include<stdio.h>
#include<fcntl.h>
#include<errno.h>
#include<iostream>
#include<string.h>
using namespace std;
int main(){
    int fd= open("no",O_RDONLY);
    if(fd<0){
        printf("errno=%d,error:%s\n",errno,strerror(errno));
    }

    int k=3,s[2];
    s[0]=k;
    k=s[1]*10;
    cout<<s[0]<<" "<<k <<endl;
    const float pi= 3.1415926f;
    return 0;
}
