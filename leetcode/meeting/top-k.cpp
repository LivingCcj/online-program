#include<iostream>
#include<vector>
using namespace std;
void swap(vector<int> &data,int a, int b)
{
    int tmp =data[a];
    data[a]=data[b];
    data[b]=tmp;
}
int partition(vector<int> &a, int l, int r)
{
    swap(a,l,(l+r)>>2);
    int i=l;
    for(int k=l+1;k<=r;k++){
        if(a[k]<a[l]){
            i++;
            swap(a,i,k);
        }
    }
    swap(a,l, i);
    return i;
}
int quickSort(vector<int> &a, int l, int r, int K)
{

    int idx = partition(a, l, r);
    // cout<<a[idx]<<endl;
    if (idx == K)
    {
        // cout<<a[idx]<<"  ** "<<endl;
        return a[idx];
    }
    else if (idx < K)
    {
        quickSort(a, idx + 1, r, K);
    }
    else
    {
        quickSort(a, l, idx - 1, K);
    }
}
int findKth(vector<int> &a, int n, int K)
{
    // write code here
    //int len=n-K;
    // cout << quick    Sort(a, 0, n - 1, K )<<endl;
    int minK=n-K;
    return quickSort(a, 0, n - 1, minK );
}


//
int sqrt(int x) {
        // write code here
        int res=x;
        long long i=1;
        while(i){
            if(i*i>=x){
                break;
            }
            i=i*2;
            // cout<<i*i<<endl;
        }
        // cout<<i<<endl;
        for(int j=i/2;j<=i;j++){
            if(j*j<=x && (j+1)*(j+1)>x){
                res=j;
                break;
            }
        }
        return res;
    }

int main(){
    vector<int> data{1,3,5,2,2};
    // int len=data.size();
    // cout<<len<<endl;
    // cout<<findKth(data,len,5)<<endl;

    //平方根
    int n=1518991037;
    cout<<n<<endl;
    cout<<sqrt(n)<<endl;
    return 0;
}