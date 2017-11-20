#include <iostream>
#include <vector>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root)return true;
        if(!root->left && !root->right){
            return true;
        }
        vector<int> res=preOrder(root);
        int size = res.size();
        for(int i = 0;i<size-1;i++){
            if(res[i+1]<=res[i]){
                return false;
            }
        }
        return true;
    }
    bool isValidBST2(TreeNode* root) {
        if(!root)return true;
        if(!root->left && !root->right){
            return true;
        }
        if(!isValidBST2(root->left)){
            return false;
        }
        if(!isValidBST2(root->right)){
            return false;
        }
        int ml = 0;
        TreeNode *left = root->left;
        while(left){
            ml = left->val;
            left = left->right;
        }
        if(ml>=root->val){
            return false;
        }
        int mr = 0;
        TreeNode *right = root->right;
        while(right){
            mr = right->val;
            right = right->left;
        }
        if(mr<=root->val){
            return false;
        }
        return true;
    }

    vector<int> preOrder(TreeNode* root){
        vector<int> res;
        if(!root) return res;
        vector<int> left = preOrder(root->left);
        if(!left.empty()){
            res.insert(res.end(),left.begin(),left.end());
        }
        res.push_back(root->val);
        vector<int> right = preOrder(root->right);
        if(!right.empty()){
            res.insert(res.end(),right.begin(),right.end());
        }
        return res;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}