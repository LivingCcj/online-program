/*
 * @Description: 最长包含字串：面试题目
 * 双指针用法，
 * @Author: ccj
 * @Date: 2020-12-18 13:25:00
 * @LastEditTime: 2020-12-18 15:33:03
 * @LastEditors:  
 */



#include<iostream>
#include<string.h>
#include<unordered_map>
using namespace std;
const int N = 100,INF=1e9;;
char a[N],b[N];
int main(){
    cin>>a>>b;

    int la=strlen(a);
    int lb=strlen(b);

    unordered_map<char,int> hmap;

    for(int i=0;i<lb;i++){
        hmap[b[i]]++;
    }
    int l=0,r=0;
    int len=lb;
    int rMin=INF;
    
    while(r<la){
        hmap[a[r]]--;
        if(hmap[a[r]]>=0){  //核心2：>=零，表示有新的元素（未被加入的元素）被加入到了i-j之间。
            len--;
        }

        if(len==0){
            while(hmap[a[l]]<0){  //核心，小于0表示i-j之间包含所有的所有b元素
                hmap[a[l++]]++;
            }
            rMin=min(rMin,r-l+1);
            len++;
            hmap[a[l++]]++;
        }
        r++;
    }
    if(rMin!=INF){
        cout<<rMin<<endl;

    }else{
        cout<<"0"<<endl;
    }
}

