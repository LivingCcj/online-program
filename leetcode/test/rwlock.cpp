#include<iostream>
#include<unistd.h>
#include<stdio.h>
#include<pthread.h>

using namespace std;

static int number=0;

static pthread_rwlock_t lock;

void* write_func(void *argc){

    while(1){
        pthread_rwclock_wrlock(&lock);
        number++;
        // std::cout<<"==== write:"<<number<<endl;
        printf(" ==== write: %ld,%d\n",pthread_self(),number);
        pthread_rwclock_unlock(&lock);
        usleep(50);
    }
    return NULL;
}

void* read_func(void *argc){

    while(1){
        pthread_rwclock_rdlock(&lock);
        printf(" ---- read:  %ld,%d\n",pthread_self(),number);
        // std::cout<<" ---- read:"<<number<<endl;
        pthread_rwclock_unlock(&lock);
        usleep(50);
    }   
    return NULL;
}

int main(){

    pthread_t p[8];
    pthread_rwlock_init(&lock,NULL);
    int i=0;
    for(;i<3;i++){
        pthread_create(&p[i],NULL,write_func,NULL);
    }
    for(i=3;i<8;i++){
        pthread_create(&p[i],NULL,read_func,NULL);
    }
    
    for(int j=0;j<8;j++){
        pthread_join(p[j],NULL);
    }
    pthread_rwlock_destory(&lock);

}