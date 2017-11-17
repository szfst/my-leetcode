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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        if(!root) return res;
        vector<int> before;
        _pathSum(root,sum,before,res);
        return res;
    }
    void _pathSum(TreeNode* root,int sum,vector<int> before,vector<vector<int>> &res){
        before.push_back(root->val);
        if(!root->left && !root->right ){
            if(root->val==sum){
                res.push_back(before);
            }else{
                return;
            }
        }
        if(root->left){
            _pathSum(root->left,sum-root->val,before,res);
        }
        if(root->right){
            _pathSum(root->right,sum-root->val,before,res);
        }
    }

};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}