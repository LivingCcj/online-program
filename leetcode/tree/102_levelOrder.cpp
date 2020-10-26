#include<bits/stdc++.h>
#include<tree.h>

using namespace std;


// struct TreeNode
// {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode(int x):val(x),left(nullptr),right(nullptr){};
// };
//层序遍历
vector<vector<int>> levelOrder(treeNode* root) {
        queue<treeNode*> q;
        vector<vector<int>> res;
        if(root == nullptr) return res;
        q.push(root);
        int start=0;
        int end=1;
        while(!q.empty()){
            vector<int> tvec;
            int tend = end;
            while(start < tend){
                treeNode* t = q.front();
                tvec.push_back(t->val);
                if(t->left) {
                    q.push(t->left);
                    end++;
                }
                if(t->right){
                    q.push(t->right);
                    end++;
                }
                q.pop();
                start++;
            }
            res.push_back(move(tvec));
        }
        return res;
}


int main(){
    Tree* tree = new Tree();
    treeNode* root=tree->buildTree();
    vector<vector<int>> res= levelOrder(root);
    if(res.size()==0) return 0;

    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j]<<",";
        }
        cout<<endl;
    }
    return 0;
}