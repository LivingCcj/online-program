#include<bits/stdc++.h>
// #include<iostream>


using namespace std;

//sizeof 和 tmp的区别
 
#define _sizeof(T) ((size_t)(T*)0+1);

int strLen(const char * str){
    int res=0;
    if(str==nullptr){
        return res;
    }
    while(*str){
        res++;
        *str++;
    }
    return res;
}

void strCpy(char * dst,char * src){
    
    if(dst==nullptr && src==nullptr){
        return;
    }
    int len=0;
    char * tmp=src;
    while(*tmp++){
        len++;
    }
    int n=len>>1;
    for(int i=0;i<n;i++){
        *dst=*src;
        *dst++;
        *src++;
    }
    *dst='\0';

}
//反转字符串
void revese(char *str){
    if(str==nullptr){
        return;
    }
    int len=0;
    char *tmp=str;

    while(*tmp++){
        len++;
    }
    int i=0;
    int j=len-1;
    while(i<j){
        char tmp=str[i];
        str[i]=str[j];
        str[j]=tmp;
        i++;
        j--;
    }
}

void revese1(char *str){
    if(str==nullptr){
        return;
    }
    int len=0;
    char *start=str;
    char *end=str+strlen(str)-1;

    while(start<end){
        char tmp=*start;
        *(start++)=*end;
        *end--=tmp;
    }
    
}

int main(){
    // const char tmp*="hello";
    char tmp[]="hello world";
    cout<<strLen(tmp)<<endl;
    const char * tmp1="\0";
    cout<<strLen(tmp1)<<endl;


    cout<<sizeof("\0")<<endl;
    cout<<sizeof('\0')<<endl;
    // cout<<sizeof('abdc')<<endl;

    // char *dst=(char*) malloc(strLen(tmp)+1);
    char dst[3];
    cout<<sizeof(dst)<<endl;
    memset(dst,'\0',sizeof(dst)/sizeof(char));
    cout<<dst<<endl;
    strCpy(dst,tmp);
    cout<<dst<<endl;

    //反转字符串

    revese1(tmp);
    // cout<<tmp<<endl;

    for(int i=0;i<strLen(tmp);i++){
        cout<<*(tmp+i)<<endl;
    }

} 