#include<bits/stdc++.h>
#include<sys/types.h>
#include<unistd.h>

using namespace std;

const int MAX=100;
int main(){
    int fd[2],n;
    char c;
    pid_t pid;
    char line[MAX];
    if(pipe(fd)<0){
        cout<<"pipe error"<<endl;
    }
    if((pid=fork())<0){
        cout<<"fork error"<<endl;
    }else if(pid==0){  //子线程
        close(fd[1]); //关闭写端
        n=read(fd[0],line,MAX); 
        write(STDOUT_FILENO,line,n); //开启读端
        sleep(1);
        cout<<" child pid="<<getpid()<<endl;
    }else{ //父进程
        close(fd[0]); //关闭读端
        write(fd[1],"hello world\n",16); //开始写数据到写入端
        sleep(2);
        cout<<"parent pid ="<<getpid()<<endl;
    }
    return 0;

}