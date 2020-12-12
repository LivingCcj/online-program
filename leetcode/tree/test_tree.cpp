#include<tree.h>

using namespace std;


//build  tree  by in and pre
vector<int> pre={1,2,4,7,3,5,6,8};
vector<int> in= {4,7,2,1,5,3,8,6};

treeNode* buildTree(vector<int> &pre,vector<int> &in){
    int len=in.size();
    if(len==0) return nullptr;
    vector<int> pre1,pre2,in1,in2;
    
    int tmp=pre[0];
    treeNode* t1=new treeNode(tmp);
    int i=0;
    for(;i<in.size();i++){
        if(tmp==in[i]){
            break;
        }
    }
    for(int j=0;j<in.size();j++){
        if(j<i){
            pre1.push_back(pre[j+1]);
            in1.push_back(in[j]);
        }else if(j>i){
            pre2.push_back(pre[j]);
            in2.push_back(in[j]);
        }
    }
    t1->left=buildTree(pre1,in1);
    t1->right=buildTree(pre2,in2);
    return t1;
}


int main(){
    Tree* tree=new Tree();
    treeNode *root=tree->buildTree();

    treeNode *root1=buildTree(pre,in);
    cout<<" 递归法："<<endl;
    tree->printMid(root1);
    cout<<endl;
    cout<<" 迭代法: "<<endl;
    tree->printMid1(root1);
    cout<<endl;
}