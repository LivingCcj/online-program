#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<assert.h>
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<poll.h>
#include<fcntl.h>

#define BUFFER_SIZE 64

int main(int argc,char* argv[]){
    if(argc<=2){
        printf("Usage:%s ip_address port_numer \n",basename(argv[0]));
        return 1;
    }

    const char* ip=argv[1];
    int port=atoi(argv[2]);
    struct sockaddr_in server_addr;
    bzero(&server_addr,sizeof(server_addr));
    server_addr.sin_family=AF_INET;
    inet_pton(AF_INET,ip,&server_addr.sin_addr);
    server_addr.sin_port=htons(port);

    int sockfd=socket(PF_INET,SOCK_STREAM,0);
    assert(sockfd>=0);
    int connfd=connect(sockfd,(struct sockaddr*)&server_addr,sizeof(server_addr));
    if(connfd<0){
        printf(" connection failed!\n");
        close(sockfd);
        return 1;
    }
    printf(" connection ok fd:=%d!\n",connfd);

    pollfd fds[2];
    //注册文件描述符为0 标准输入，文件描述符sockfd可读事件

    fds[0].fd=0;
    fds[0].events=POLLIN;
    fds[0].revents=0;
    fds[1].fd=sockfd;
    fds[1].events= POLLIN | POLLRDHUP;
    fds[1].revents=0;
    char read_buf[BUFFER_SIZE];
    char write_buf[BUFFER_SIZE];
    
    int pipefd[2];
    int ret=pipe(pipefd);
    assert(ret!=1);
    while (1)
    {
        /* code */
        ret=poll(fds,2,-1);
        if(ret<0){
            printf("poll failue\n");
            break;
        }
        if(fds[1].revents & POLLRDHUP){
            printf("server close the connection\n");
            break;
        }
        else if(fds[1].revents & POLLIN){
            memset(read_buf,'\0',sizeof(read_buf));
            recv(fds[1].fd,read_buf,BUFFER_SIZE-1,0);
            printf("server say:%s\n",read_buf);
        }
        if(fds[0].revents & POLLIN){
            ret=splice(0,NULL,pipefd[1],NULL,32768,SPLICE_F_MORE| SPLICE_F_MOVE);
            ret=splice(pipefd[0],NULL,sockfd,NULL,32768,SPLICE_F_MORE| SPLICE_F_MOVE);
            
            // memset(write_buf,'\0',size_of(write_buf));
            // write_buf="hello ";
            // send(connfd,write_buf,sizeof(write_buf),0);
        }
    }
    close(sockfd);
    return 0;
}

