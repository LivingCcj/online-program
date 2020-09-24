#include<iostream>
#include<vector>

using namespace std;

int getIdx(vector<int> &a, int i, int j, int v)
{
    if (j < i)
    {
        return a.size() + 1;
    }
    int mid = (i + j) / 2;
    // cout<<(i+j)/2<< " "<<a[mid] << " "<<v<<endl;
    if (a[mid] == v)
    {
        int res=mid;
        for(int i=mid;i>=0;){
            if(a[i]==v){
                i--;
            }else{
                res=i+1;
                break;
            }
        }
        return i==-1?1:res + 1;
    }
    else if (a[mid] > v)
    {
        getIdx(a, i, mid - 1, v);
    }
    else
    {
        getIdx(a, mid + 1, j, v);       
    }
}
int upper_bound_(int n, int v, vector<int> &a)
{
    // write code here
    return getIdx(a, 0, n - 1, v);
}
int main(){
    int n=5;
    int v=4;
    vector<int> data={1,2,4,4,5};
    cout<<upper_bound_(n,v,data)<<endl;
}