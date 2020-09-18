#include<iostream>
#include<string>


using namespace std;

int main(){
    const int MAX=36;
    int* record=new int[MAX]();
    string str;
    int n=6;
    int count=0;
    int noBuildNum=0;
    while(n--){
        cin>>str;
        for(int i=0;i<6;i++){
            if(str[i]=='#')
                record[count]=1;
                noBuildNum++;
            count++;
        }
    }
    // for(int j=0;j<MAX;j++){
    //     cout<<record[j]<<endl;
    // }
    long long res;
    res=noBuildNum
    for(int i=0;i)
    cout<<res<<endl;
    delete[] record;
    return 0;
}