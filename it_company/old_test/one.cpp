#include<iostream>
#include<stdio.h>
#include<signal.h>
#include<time.h>
#include<sys/types.h>
#define N 2008
using namespace std;


int main(){
    cout<<"hello world"<<endl;
    int l=300,s=300;
    int n=100;
    int num[N];
    FILE *fp;
    fp=fopen("test.txt","a+");
    // rewind(fp);
    while(1){
        char ch=fgetc(fp);
        if(feof(fp)){
            break;
        }
        cout<<ch<<endl;
    }   
    cout<<(s+l>>1)<<endl;
    pid_t pid;
    singal(SIGCHLD,SIG_IGN);
    printf("before fork id:%d\n",getpid());
    int abc=10;
    pid=fork();
    if(pid==-1){
         perror("tile");
         return -1;
    }
    if(pid>0){
        abc++;
        printf("parent:pid:%d\n",getpid());
        printf("abc:%d\n",abc);
        sleep(20);
    }
    else if(pid==0){
        abc++;
        printf("child:pid:%d,parent:pid:%d\n",getpid(),getppid());
        printf("abc:%d\n",abc);
    }
    printf("fork after ....\n");
    return 0;
}
