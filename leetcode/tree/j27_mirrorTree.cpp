
#include<tree.h>

using namespace std;


treeNode* mirrorTree(treeNode *root){
    if(root==nullptr) return nullptr;
    treeNode * tmp=root->left;
    root->left=mirrorTree(root->right);
    root->right=mirrorTree(tmp);
    return root;
}
int main(){

    Tree *tree=new Tree();

    treeNode *root= tree->buildTree();
    tree->printMid(root);
    cout<<endl;
    mirrorTree(root);
    tree->printMid(root);
    cout<<endl;

    delete tree;
    delete root; 
    return 0;
}
