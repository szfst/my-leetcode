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
    int sumOfLeftLeaves(TreeNode* root) {
        if(root== nullptr){
            return 0;
        }
        int sum = 0;
        if(isLeaf(root->left)){
            sum=root->left->val+sumOfLeftLeaves(root->right);
        }else{
            sum=sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);
        }
        return sum;
    }
    bool isLeaf(TreeNode* root){
        return root!=nullptr && root->left == nullptr && root->right == nullptr;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}