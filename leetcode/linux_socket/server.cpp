#include<sys/types.h>
#include<sys/socket.h>

#include<netinet/in.h>
#include<arpa/inet.h>
#include<assert.h>
#include<stdio.h>
#include<unistd.h>
#include<errno.h>
#include<string.h>
#include<fcntl.h>
#include<stdlib.h>
#include<poll.h>

#define USER_LIMIT 5
#define BUFFER_SIZE 64
#define FD_LIMIT 65335

struct client_data{
    sockaddr_in address;
    char* write_buf;
    char buf[BUFFER_SIZE];
};


int setnoblocking(int fd){
    int old_option=fcntl(fd, F_GETFL );
    int new_option= old_option | O_NONBLOCK;
    fcntl(fd,F_SETFL,new_option);
    return old_option;
}

int main(int argc,char* argv[]){
    if(argc<=2){
        printf("Usage:%s ip_address port_numer \n",basename(argv[0]));
        return 1;
    }
    const char*ip=argv[1];
    int port=atoi(argv[2]);
    int ret=0;
    struct sockaddr_in sock_addr;
    bzero(&sock_addr,sizeof(sock_addr));

    sock_addr.sin_family=AF_INET;
    inet_pton(AF_INET,ip,&sock_addr.sin_addr);
    sock_addr.sin_port=htons(port);

    int listenfd=socket(PF_INET,SOCK_STREAM,0);

    assert(listenfd>=0);
    ret=bind(listenfd,(struct sockaddr*)&sock_addr,sizeof(sock_addr));

    assert(ret!=-1);
    ret=listen(listenfd,5);

    assert(ret!=-1);

    client_data* users=new client_data[FD_LIMIT];
    pollfd fds[USER_LIMIT+1];

    int user_count=0;
    for(int i=1;i<=USER_LIMIT;i++){
        fds[i].fd=-1;
        fds[i].events=0;
    }

    fds[0].fd=listenfd;
    fds[0].events=POLLIN | POLLERR;
    fds[0].revents=0;

    while(1){
        ret=poll(fds,user_count+1,-1);
        if(ret<0){
            printf("poll failed\n");
            break;
        }
        for(int i=0;i<user_count+1;i++){
            if((fds[i].fd==listenfd) && (fds[i].events & POLLIN)){
                struct sockaddr_in client_addr;
                socklen_t c_addr_len=sizeof(client_addr);
                int connfd=accept(listenfd,(struct sockaddr*) &client_addr,&c_addr_len);
                
                printf("a user connnect into server!\n");
                if(connfd<0){
                    printf("errno is : %d\n",connfd);
                    continue;
                }
                if(user_count>=USER_LIMIT){
                    const char* info="too many users\n";
                    printf("%s",info);
                    send(connfd,info,strlen(info),0);
                    close(connfd);
                    continue;
                }
                user_count++;
                users[connfd].address = client_addr;
                setnoblocking(connfd);
                
                fds[user_count].fd = connfd;
                fds[user_count].events = POLLIN | POLLRDHUP | POLLERR;
                fds[user_count].revents = 0;
                printf("comes a new uesr, now have %d users\n", user_count);
        }
        else if(fds[i].revents & POLLERR){
            printf("get an error from %d\n",fds[i].fd);
            char errors[100];
            memset(errors,'\0',100);
            socklen_t length=sizeof(errors);
            if(getsockopt(fds[i].fd,SOL_SOCKET,SO_ERROR,&errors,&length)<0){
                printf("get socket option failed\n");
            }
            continue;
        }
        else if(fds[i].revents & POLLRDHUP){
            //备注最后的一个客户端的连接句柄
            users[fds[i].fd]=users[fds[user_count].fd];
            close(fds[i].fd);
            i--;
            user_count--;
            printf("a client left \n");
        }
        else if(fds[i].revents & POLLIN){
            int connfd=fds[i].fd;
            memset(users[connfd].buf,'\0',BUFFER_SIZE);     
            ret=recv(connfd,users[connfd].buf,BUFFER_SIZE-1,0);
            printf("get %d bytes of client data %s from connfd=%d \n",ret,users[connfd].buf,connfd);
            if(ret<0){
                if(errno != EAGAIN){
                    close(connfd);
                    users[fds[i].fd]=users[fds[user_count].fd];
                    fds[i]=fds[user_count];
                    i--;
                    user_count--;
                }
            }
            else if(ret==0){

            }else{
                for(int j=1;j<=user_count;j++){
                    if(fds[j].fd ==connfd){
                        continue;
                    }
                    fds[j].events |= ~POLLIN;
                    fds[j].events |= POLLOUT;
                    //把客户端的话再返回回去
                    char reback[BUFFER_SIZE]="this is client";
                    users[fds[j].fd].write_buf=reback;
                }
            }
        }
        else if(fds[i].events & POLLOUT){
            int connfd=fds[i].fd;
            if(!users[connfd].write_buf){
                continue;
            }
            ret =send(connfd,users[connfd].write_buf,strlen(users[connfd].write_buf),0);
            //写完数据之后，注册为可读事件。
            users[connfd].write_buf=NULL;
            fds[i].events |= ~POLLOUT;
            fds[i].events |= POLLIN;
        }
        }
    }
    delete [] users;
    close(listenfd);
    return 0;

}

