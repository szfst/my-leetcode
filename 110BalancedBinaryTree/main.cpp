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
    bool isBalanced(TreeNode* root) {
        if(root== nullptr){
            return true;
        }
        return (abs(treeDepth(root->left)-treeDepth(root->right))<=1)&&isBalanced(root->left) && isBalanced(root->right);
    }
    int treeDepth(TreeNode *root){
        if(!root){
            return 0;
        }
        return max(treeDepth(root->left),treeDepth(root->right))+1;
    }

    bool isBalancedAdvance(TreeNode* root) {
        if(root== nullptr){
            return true;
        }
        return getDepth(root)!=-1;
    }
    //if the tree is not a balance true,depth return -1
    int getDepth(TreeNode *root){
        if(!root){
            return 0;
        }
        int ld = getDepth(root->left);
        int rd = getDepth(root->right);
        if(ld==-1 || rd== -1 || abs(rd-ld)>1){
            return -1;
        }
        return max(ld,rd)+1;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}