#include <iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        //the end of the recursion is that root is null or below
        if(root== nullptr){
            return false;
        }
        int value = root->val;
        //the end of the recursion is that root is the leaf(has not child) and sum is value
        if(!root->left && !root->right && value == sum){
            return true;
        }
        return hasPathSum(root->left,sum-value) || hasPathSum(root->right,sum-value);


    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}