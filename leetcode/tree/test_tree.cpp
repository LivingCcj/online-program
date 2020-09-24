#include<tree.h>

using namespace std;

int main(){
    Tree* tree=new Tree();
    treeNode *root=tree->buildTree();

    cout<<" 递归法："<<endl;
    tree->printMid(root);
    cout<<endl;
    cout<<" 迭代法: "<<endl;
    tree->printMid1(root);
    cout<<endl;
}