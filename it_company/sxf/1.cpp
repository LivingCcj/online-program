#include<iostream>
#include<vector>
#include<limits.h>
#include<stack>
#include<algorithm>
using namespace std;


int getMax(vector<int> data){

    int len=data.size();
    if(len<3) return 0;
    int left=0;
    int right=data.size()-1;
    int leftMax=0;
    int rightMax=0;
    int res=0;
    while(left<right){
        if(data[left]<data[right]){
            if(data[left]>=leftMax){
                leftMax=data[left];
            }else{
                res+=leftMax-data[left];
            }
            left++;
        }else{
            if(data[right]>=rightMax){
                rightMax=data[right];
            }else{
                res+=rightMax-data[right];
            }
            right--;
        }

    }
}

int main(){
    int w,l;
    cin>>w>>l;
    vector<int> data(l);
    int d;
    for(int i=0;i<l;i++){
        cin>>data[i];
    }

    int sum=0;

    for(int i=0;i<data.size()-2;i++){
        int lmax=0;
        int rmax=0;
        cout<<i<<"  "<<data[i]<<endl;
        for(int l=0;l<i+1;l++){
            lmax=max(lmax,data[l]);
        }
        for(int r=i;r<data.size();r++)
        {
            rmax=max(rmax,data[r]);
        }
        if(rmax<=data[i]){
            continue;
        }
        cout<<"sum:"<<max(rmax,lmax)-data[i]<<endl;
        sum+=max(rmax,lmax)-data[i];
    }  

    int res=sum*w;
    cout<<res<<endl;
    return 0;
}
