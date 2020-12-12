#include<iostream>

using namespace std;
//题目地址:https://www.acwing.com/problem/content/description/792/

double cul(double a){
    return a*a*a;
}
int main(){
    double n;
    cin>>n;
    double l=-10000,r=10000;
    //二分法
    while (r-l>=1e-7)
    {
        double mid =(l+r)/2;
        if(cul(mid)>=n) r=mid;
        else l = mid;
    }
    printf("%.6lf\n",l);
    return 0;
    
}