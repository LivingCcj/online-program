#include<tree.h>
#include<iostream>
#include<vector>
using namespace std;


//查询路径和为某个定值。 使用dfs的方法
vector<vector<int>> res;
vector<int> tmp;
int resum;

void dfs(treeNode* root,int sum){
    if(root!=nullptr){
        tmp.push_back(root->val);
        sum=sum-root->val;
        if(sum==0 && root->left==nullptr && root->right==nullptr){
            res.push_back(tmp);
        }
        if(root->left!=nullptr){
            dfs(root->left,sum);
        }
        if(root->right!=nullptr){
            dfs(root->right,sum);
        }
        tmp.pop_back(); //回溯
    }
}

vector<vector<int>> pathSum(treeNode *root,int sum){
    if(root){
        dfs(root,sum);
    }
    return res;
}


int main(){
    Tree *tree=new Tree();
    treeNode *root=tree->buildTree();
    int sum =21;
    pathSum(root,sum);

    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[0].size();j++){
            cout<<res[i][j]<<endl;
        }
    }
}