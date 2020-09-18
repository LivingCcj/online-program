#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    string s;
    int m,n;
    cin>>n>>m;
    vector<vector<int> > data(n,vector<int>(m));
    for_each(data.begin(),data.end(),[](vector<int> vec){
        for(int i=0;i<vec.size();i++){
            cout<<vec[i]<<" ";
        }
        cout<<endl;
    });
    // int sum=0;
    for(int i=0;i<data.size();i++){
        for(int j=0;j<data[i].size();j++){
            data[i][j]=i+j*5;
        }
    }

    for_each(data.begin(),data.end(),[](vector<int> vec){
        for(int i=0;i<vec.size();i++){
            cout<<vec[i]<<" ";
        }
        cout<<endl;
    });
    for(int i=0;i<data.size();i++){
        for(int j=0;j<data[i].size();j++){
            cout<<data[i][j]<<" ";
        }
        cout<<endl;
    }
    while(getline(cin,s)){
        cout<<"hello:"<<s<<endl;
    }
   
    return 0;
}
