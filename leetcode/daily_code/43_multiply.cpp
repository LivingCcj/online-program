#include<iostream>
#include<string>
#include<stdlib.h>
#include<sstream>
/*
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
大数相乘
*/
using namespace std;

string multiply(string num1, string num2) {
    if(atoi(num1.c_str())==0 || atoi(num2.c_str())==0){
        return "0";
    }
    string mul1;  //big
    string mul2;  //small
    if(num1.compare(num2)>0){
        mul2=num2;
        mul1=num1;
    }else{
        mul2=num1;
        mul1=num2;
    }

    int minLen=mul2.size();
    int maxlen=mul1.size();
    string record1;
    string record2;
    while(maxlen--){
        record1.push_back('0');
    }
    stringstream ss;
    string ins;
    // cout<<mul1<<" "<<mul2<<endl;
    for(int i=minLen-1;i>=0;i--){
        string tmp;
        int m=i;
        while(minLen-1-m){
            tmp.push_back('0');
            m++;
        }
        int cur=mul2[i]-'0';
        int record=0;
        for(int j=mul1.size()-1;j>=0;j--){
            int v1=((mul1[j]-'0')*cur)+record;
            int value1=v1%10;
            if(j==0){
                ss<<v1;
            }else{
                ss<<value1;
            }
            ss>>ins;
            tmp.insert(0,ins);
            ss.clear();
            record=v1/10;
        }
        // cout<<"tmp:"<<tmp<<"  record1:"<<record1<<endl;
        record=0;
        int n=record1.size()-1;
        int k=tmp.size()-1;
        for(;k>=0 && n>=0;){
            int v2=tmp[k]-'0' + record1[n]-'0'+record;
            int value2=v2%10;
            if(k==0){
               ss<<v2;
           }else{
               ss<<value2;
           }
            ss>>ins;
            ss.clear();
            record2.insert(0,ins);
            record=v2/10;
            k--;n--;
        }
        // cout<<k<<"  record2:"<<record2<<endl;
        while(k>=0){
           int v3=tmp[k]-'0'+record;
           int value3=v3%10;
           if(k==0){
               ss<<v3;
           }else{
               ss<<value3;
           }
            ss>>ins;
            ss.clear();
            record2.insert(0,ins);
            record=v3/10;
            k--;
        }
        
        // cout<<"record2:"<<record2<<endl;
        ss.clear();
        swap(record2,record1);
        record2.clear();
    }
    return record1;
}



int main(){
    string num1="000";
    string num2="2";
    long num=atoi(num1.c_str())*atoi(num2.c_str());
    cout<<multiply(num1,num2)<<endl;
    cout<<num<<endl;
    return 0;
}