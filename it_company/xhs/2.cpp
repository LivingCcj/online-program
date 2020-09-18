#include <iostream>
#include <vector>
#include <numeric>
#include <limits> 
#include<stack>
using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/
int resMin =10000005;
void solution(string s,int front,int res) {
    if(s.size()==front){
        resMin=min(resMin,res-1);
    }else if((s.size()-1)==front){
        resMin=min(resMin,res);
    }
    for(int i=s.size()-1;i>=front;i--){
        if(s[i]==s[front]){
            if(resMin < (res+1)){
                continue;
            }
            solution(s,i+1,res+1);
        }
    }
                                                                      
}
/******************************结束写代码******************************/


int main() {
    int res;

    string _s;
    getline(cin, _s);

    solution(_s,0,1);
    cout << resMin << endl;
    
    return 0;

}
