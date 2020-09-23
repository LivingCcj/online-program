#include<iostream>
#include<string>

using namespace std;

int main(){
    int n;
    cin>>n;
    string str;
    int count=0;
    while(n--){
        cin>>str;
        int flag=true;
        for(int i=0;i<str.size();i+=3){
            for(int j=i+3;j<str.size();){
                count=0;
                for(int k=0;k<3;k++){
                    if(str[i+k]==str[j+k]){
                        count++;
                    }
                }
                if(count<2){
                    flag=false;
                    break;
                }
                j+=3;
            }
            if(!flag){
                break;
            }
        }
        if(flag){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}