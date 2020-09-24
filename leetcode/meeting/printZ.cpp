#include<iostream>
#include<vector>
#include<stack>
#include<tree.h>

using namespace std;

vector<vector<int>> zigzagLevelOrder(treeNode* root) {
        // write code here
        stack<treeNode*> first;
        stack<treeNode*> second;
        int i=0;
        first.push(root);
        treeNode *tmp;
        vector<vector<int>> res;
        vector<int> data;
        while(!first.empty() || !second.empty()){
            if(i%2==0){
                while(!first.empty()){
                    tmp=first.top();
                    data.push_back(tmp->val);
                    cout<<tmp->val<<" ";
                    first.pop();
                    if(tmp->left!=nullptr){
                        second.push(tmp->left);
                    }
                    if(tmp->right!=nullptr){
                        second.push(tmp->right);
                    }
                    
                }
                res.push_back(data);
                data.clear();
                i++;
                cout<<endl;
            }else{
                while(!second.empty()){
                    tmp=second.top();
                    data.push_back(tmp->val);
                    cout<<tmp->val<<" ";
                    second.pop();
                    if(tmp->right!=nullptr){
                        first.push(tmp->right);
                    }
                    if(tmp->left!=nullptr)
                    {
                        first.push(tmp->left);
                    }                    
                }
                res.push_back(data);
                data.clear();
                i++;
                cout<<endl;
            }
            // if(i==5){
            //     break;
            // }
        }
        return res;
}

int main(){
    Tree *tree=new Tree();
    treeNode *root=tree->buildTree();
    zigzagLevelOrder(root);
}