/*
 * @Description: 模板化组合数 ：https://www.acwing.com/problem/content/887/
 * 
 * 核心思想有点dp的味道
 * c[a][b]=c[a-1][b-1]+c[a-1][b]  表示第a个苹果再在不在抽取的b个苹果中。
 * @Author: ccj
 * @Date: 2020-12-16 11:13:05
 * @LastEditTime: 2020-12-16 11:15:01
 * @LastEditors:  
 */





#include<iostream>

using namespace std;

const int N =2010,P=1e9+7;

int c[N][N];

void init(){
    for(int i=0;i<N;i++){
        for(int j=0;j<=i;j++){
            if(!j) c[i][j]=1; //初始化都为1
            else{
                c[i][j]=(c[i-1][j]+c[i-1][j-1])% P;
            }
        }
    }
    
}

int main(){
    int n;
    cin>>n;
    int a,b;
    init();
    while(n--){
        cin>>a>>b;
        cout<<c[a][b]<<endl;
    }
    return 0;
}