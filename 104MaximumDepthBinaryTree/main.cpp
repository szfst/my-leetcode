#include <iostream>
using namespace std;
class Solution {
     struct TreeNode {
       int val;
       TreeNode *left;
       TreeNode *right;
       TreeNode(int x) : val(x), left(NULL), right(NULL) {}
   };
public:
    int maxDepth(TreeNode* root) {
        if(root== nullptr){
            return 0;
        }
        int right = maxDepth(root->right);
        int left = maxDepth(root->left);
        if(left>right){
            return left+1;
        }else{
            return right+1;
        }

    }
    int maxDepth2(TreeNode* root) {
        return root== nullptr?0:max(maxDepth2(root->right),maxDepth2(root->left))+1;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}