#include<iostream>
#include<string>
#include<set>
#include<map>
using namespace std;


bool checkIncludion(string &str1,string &str2){
    int len2=str2.size();
    if(len2==0) return false;
    map<char,int> check;
    for(int i=0;i<str2.size();i++){
        check[str2[i]]++;
    }

    int rx=-1;
    int len1=str1.size();
    bool flag=false;

    for(int j=0;j<len1;j++){
        rx=j;
        map<char,int> tmp=check;
        while(rx<len1 && tmp.count(str1[rx])>0){
            tmp[str1[rx]]--;
            rx++;
        }
        auto iter=tmp.begin();
        flag=true;
        while(iter!=tmp.end()){

            if(iter->second!=0){
                flag=false;
                break;
            }
            iter++;
        }
        if(flag){
            break;
        }
    }

    return flag;
}
int main(){

    string str1;
    string str2;

    cin>>str1>>str2;
    

    cout<<checkIncludion(str1,str2)<<endl;

}
