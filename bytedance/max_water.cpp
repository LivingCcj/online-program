/*
 * @Description: 双指针，接雨水：https://www.nowcoder.com/practice/31c1aed01b394f0b8b7734de0324e00f?tpId=117&&tqId=1002045

 * @Author: ccj
 * @Date: 2020-12-15 10:43:36
 * @LastEditTime: 2020-12-15 11:32:51
 * @LastEditors:  
 */

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long LL;

//nice idea 双指针，从头和尾出发
//时间复杂度O(lgN) O(1);
LL maxWater(vector<int> &arr){
    

    int lmax=0,rmax=0;
    long long res=0;
    int l=0,r=arr.size()-1;
    while(l<r){
        lmax=max(arr[l],lmax);
        rmax=max(arr[r],rmax);

        if(lmax<rmax){
            res+=lmax-arr[l];
            l++;
        }else{
            res+=rmax-arr[r];
            r--;
        }
    }
    return res;
}

//good idea 从左到右，从右到左保存最大值 通过
//时间复杂度 O(N),空间复杂度O(N);


LL maxWater1(vector<int> &arr){
    int len=arr.size();
    if(!len) return 0;
    vector<int> la(len,0);
    vector<int> ra(len,0);

    la[0]=arr[0];
    ra[len-1]=arr[len-1];
    for(int i=1;i<len;i++){
        la[i]=max(la[i-1],arr[i]);
        ra[len-i-1]=max(ra[len-i],arr[len-i-1]);
    }

    long long res=0;
    for(int i=1;i<len-1;i++){
        if(min(ra[i],la[i])>arr[i]) res+=min(ra[i],la[i])-arr[i];
    }
    return res;
}


//只过了80%
LL maxWater(vector<int> &arr)
{
    long long res = 0;
    int size = arr.size();
    if (size == 0)
        return 0;
    arr.push_back(0);
    long long tmp = 0;
    for (int i = 1, j = 0; i < size;)
    {

        if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1])
        {
            int tmin = min(arr[j], arr[i]);
            res += tmin * (i - j-1) - tmp;
            tmp = 0;
            j = i;
        }
        else
        {
            tmp += arr[i];
        }
        i++;
    }
    return res;
}


int main(){

    vector<int> data{4,5,1,3,2};

    cout<<maxWater1(data)<<endl;
    return 0;
}
