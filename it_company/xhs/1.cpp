#include <iostream>
#include <vector>
#include <numeric>
#include <limits>
#include<algorithm>
using namespace std;


/*请完成下面这个函数，实现题目要求的功能
当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ 
******************************开始写代码******************************/

const int maxIdx=1000005;
int dp[1000005];

int findMin(vector < int > tree) {

    if(tree.size()==0){
        return 0;
    }

    for(int i=0;i<tree.size();i++){
        dp[tree[i]]=1;
    }
    int res=0;
    for(int i=1;i<maxIdx;i++){
        if(dp[i]!=1){
            res=i;
            break;
        }
    }
    return res;

}
/******************************结束写代码******************************/


int main() {
    int res;

    int _tree_size = 0;
    cin >> _tree_size;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n'); 
    vector<int> _tree;
    int _tree_item;
    for(int _tree_i=0; _tree_i<_tree_size; _tree_i++) {
        cin >> _tree_item;
        cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');
        _tree.push_back(_tree_item);
    }


    
    res = findMin(_tree);
    cout << res << endl;
    
    return 0;

}
