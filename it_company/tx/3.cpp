#include<iostream>


using namespace std;

long long res(int res){
    long long cnt=res;
    res--;
    if (res < 16)
    {
        while (res--)
        {
            cnt *= 2;
            cnt %= 1000000007;
        }
        return cnt;
    }
    else
    {
        int ans = 1;
        ans = ans << 16;
        while (res > 16)
        {
            cnt *= ans;
            cnt %= 1000000007;
            res = res - 16;
        }
        while (res--)
        {
            cnt *= 2;
            cnt %= 1000000007;
        }
        return cnt;
    }
}
int main(){
    int n;
    cin>>n;
    cout<<res(n)<<endl;
    // cout<<result<<endl;
    return 0;
}