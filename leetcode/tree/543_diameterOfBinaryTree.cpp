#include<tree.h>
#include<iostream>
using namespace std;


int res=1;

int depth(treeNode *root){
    if(root==nullptr) return 0;
    int left=depth(root->left);
    int right=depth(root->right);
    res=max(res,left+right);
    return max(left,right)+1;
}
//最长的路径
int main(){
    Tree *tree=new Tree();

    treeNode *root=tree->buildTree();
    cout<<"res: "<<depth(root)<<endl;
    cout<<"max path:"<<res<<endl;


}