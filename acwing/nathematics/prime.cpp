/*
 * @Description: 质数(素数)https://www.acwing.com/problem/content/868/
 * 
 * 通过试除法 时间复杂度O(sqrt（n))
 *
 * @Author: ccj
 * @Date: 2020-12-16 09:56:55
 * @LastEditTime: 2020-12-16 09:58:46
 * @LastEditors:  
 */

//试除法 时间复杂度O(sqrt（n))
#include<iostream>

using namespace std;

bool is_prime(int n){
    if(n<2) return false;
    for(int i=2;i<=n/i;i++){
            if(n%i ==0 ){
                return false;
            }
        }
    return true;
}

int main(){
    int n;
    cin>>n;
    while(n--){
        int x;
        cin>>x;
        if(is_prime(x))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}