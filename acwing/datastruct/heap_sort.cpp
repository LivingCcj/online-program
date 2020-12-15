/*
 * @Description: 堆排序：https://www.acwing.com/problem/content/840/
 * 
 * 插入操作：放到队尾，up(size)  O（lgn）
 * 删除操作: h[1]=h[size];size--;down(1) O（lgn）
 * 最小值：h[1] O（1）
 * 删除第k个元素 h[k]=h[size] size--; down(k) or up(k);  O（lgn）
 * 更新第k个元素 h[k]=value,down(k) or up(k),   O（lgn）
 * 
 * @Author: ccj
 * @Date: 2020-12-14 15:48:49
 * @LastEditTime: 2020-12-14 16:08:17
 * @LastEditors:  
 */


#include<iostream>

using namespace std;

const int N =1e5+10;

int h[N];
int sz=0;

//堆的down操作
void down(int i){
    int tmp=i;
    if(sz>=2*i && h[tmp]>h[2*i]) tmp=2*i;
    if(sz>=2*i+1 && h[tmp]>h[2*i+1]) tmp=2*i+1;
    
    if(tmp!=i){
        swap(h[tmp],h[i]);
        down(tmp);
    }
}
//堆的up操作
void up(int x){
    int tmp=x;
    if(x && x/2 && h[x]<h[x/2]) tmp=x/2;
    if(x!=tmp){
        swap(h[x],h[tmp]);
        up(tmp);
    }
}


int main(){
    int n,m;
    cin>>n>>m;
    sz=n;
    for(int i=1;i<=n;i++) cin>>h[i];
    
    //巧妙的初始堆, 时间复杂度：O(N)
    for(int i=n/2;i;i--) down(i);
    
    while(m--){
        cout<<h[1]<<" ";
        h[1]=h[sz];
        sz--;
        down(1);
    }
    return 0;
}