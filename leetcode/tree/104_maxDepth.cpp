#include<tree.h>
#include<iostream>
using namespace std;


// struct treeNode
// {
//     int val;
//     tree* left;
//     tree* right;
//     tree(int x):val(x),left(nullptr),right(nullptr){};
// };

//求树的最大深度

int maxDepth(treeNode *root){
    if(root==nullptr) return 0;
    return max(maxDepth(root->right)+1,maxDepth(root->left)+1);

}
int minDepth(treeNode *root){
    if(root==nullptr) return 0;
    return min(maxDepth(root->right)+1,maxDepth(root->left)+1);

}
int main(){
    Tree* tree=new Tree();
    treeNode* root=tree->buildTree();


    cout<<"max depth:"<<maxDepth(root)<<endl;
    cout<<"min depth:"<<minDepth(root)<<endl;

    delete tree;
    delete root;
    return 0;
}