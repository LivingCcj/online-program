#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
struct treeNode
{
    int val;
    treeNode *left;
    treeNode *right;
    treeNode(int x):val(x),left(nullptr),right(nullptr){};
};


class Tree{

public:
    treeNode* buildTree();
    void printMid(treeNode *root);
    void printPre(treeNode *root);
    void printPost(treeNode *root);

    //迭代法
    void printMid1(treeNode *root);
    void printPre1(treeNode *root);
    void printPost1(treeNode *root);
private:
    treeNode* root;
};

treeNode* Tree::buildTree(){
    treeNode *root1=new treeNode(1);
    treeNode *root2=new treeNode(2);
    treeNode *root3=new treeNode(3);
    treeNode *root4=new treeNode(4);
    treeNode *root5=new treeNode(5);
    treeNode *root6=new treeNode(6);
    treeNode *root7=new treeNode(7);
    treeNode *root8=new treeNode(8);

    // treeNode *root9=new treeNode(7);
    root1->left=root2;
    root1->right=root3;
    
    root2->left=root4;
    root2->right=root5;
    // root5->right=root9; 
    root4->left=root6;
    root4->right=root7;
    root7->right=root8;
    return root1;
};

//中序遍历
void Tree::printMid(treeNode *root){
    if(root==nullptr) return ;

    printMid(root->left);
    cout<<root->val<<" ";
    printMid(root->right);
}
//迭代中序遍历

void Tree::printMid1(treeNode *root){
    stack<treeNode *> cache;
    treeNode *tmp=root;
    while(tmp || !cache.empty()){
        if(tmp!=nullptr){
            cache.push(tmp);
            tmp=tmp->left;
        }else{
            tmp=cache.top();
            cout<<tmp->val<<" ";
            cache.pop();
            tmp=tmp->right;
        }
    }
}

//后序遍历
void Tree::printPost(treeNode *root){
    if(root==nullptr) return ;

    printPost(root->left);
    printPost(root->right);
    cout<<root->val<<" ";
}
//迭代后续遍历
void Tree::printPost1(treeNode *root){
    stack<treeNode*> cache;
    treeNode* tmp=root;
    vector<int> data;
    while(tmp || !cache.empty()){
        if(tmp){
            cache.push(tmp);
            data.push_back(tmp->val);
            cout<<tmp->val<<" ";
            tmp=tmp->right;
        }else{
            tmp=cache.top();
            cache.pop();
            tmp=tmp->left;
        }
    }
    cout<<endl;
    cout<<" 反转： ";
    reverse(data.begin(),data.end());
    for(int n:data){
        cout<<n<<" ";
    }
}

//前序遍历
void Tree::printPre(treeNode *root){
    if(root==nullptr) return ;
    
    cout<<root->val<<" ";
    printPre(root->left);
    printPre(root->right);
}

//迭代
void Tree::printPre1(treeNode *root){
    stack<treeNode*> cache;
    cache.push(root);
    treeNode* tmp=root;
    while(tmp!=nullptr || !cache.empty()){
        
        if(tmp!=nullptr){
            cache.push(tmp);
            cout<<tmp->val<<" ";
            tmp=tmp->left;
        }else{
            tmp=cache.top();
            cache.pop();
            tmp=tmp->right;
        }
    }
}


// //bad code
// void Tree::printMid(treeNode &root){
//     // if(root==nullptr) return ;
//     treeNode & left=*root.left;
//     treeNode & right=*root.right;
//     printMid(left);
//     cout<<root.val<<" ";
//     printMid(right);
// }


