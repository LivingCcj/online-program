
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

//按照6*3 为矩阵，按照第3，2，1行依次排序
bool cmp(vector<int> &a ,vector<int> &b){
    for(int i=a.size()-1;i>=0;i--){
        if(a[i]==b[i]){
            continue;
        }
        else{
            return a[i]>b[i];
        }
    }
}
int main(){
    vector<vector<int>> data={ {1,4,3}, {1,4,7} , {1,3,5} , {2,9,4} , {2,5,8} , {3,9,6} };

    sort(data.begin(),data.end(),cmp);
    for(int i=0;i<data.size();i++){
        for(int j=0;j<data[0].size();j++){
            cout<<data[i][j]<<" ";
        }
        cout<<endl;
    }

}