#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
#include<limits.h>
using namespace std;


/**
 * 给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。
 * 
 */
//BFS 遍历目标值
int numSquares(int n){
    int m=sqrt(n);
    queue<int> data;
    data.push(0);
    int step=0;
    while(!data.empty()){
        int size=data.size();
        step++;
        for(int i=0;i<size;i++){
            int front=data.front();
            data.pop();
            for(int i=1;i<=m;i++){
                int sum=front+i*i;
                if(sum==n) return step;
                if(sum>n) continue;
                data.push(sum);
            }
        }
    }
    return -1;
}
//还有一种dp的方法
int numSquares1(int n){
    vector<int> data(n+1,INT_MAX);
    data[0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j*j<=i;j++){
            data[i]=min(data[i],data[i-j*j]+1);
        }
        // for_each(begin(data),end(data),[](int x){
        //     cout<<x<<" ";
        // });
        // cout<<endl;
    }
    return data[n];
}

int main(){
    int n;
    cin>>n;
    cout<<numSquares1(n)<<endl;
    cout<<numSquares(n)<<endl;
}
