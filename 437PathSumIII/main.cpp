#include <iostream>
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        if(root== nullptr){
            return 0;
        }
        int res = 0;
        res+=pathSumWithRoot(root,sum);
        res+=pathSum(root->left,sum);
        res+=pathSum(root->right,sum);
        return res;

    }
//this function is to find the path count start at root,but does not need to end at a leaf
     int pathSumWithRoot(TreeNode* root,int sum){
         if(!root) return 0;
         int res = 0;
         int rest = sum-root->val;
         if(rest==0){
             res++;
         }
         //if rest==0,the child of this node may have negative value,add add its child maybe have another answer,so also do the next
         res+=pathSumWithRoot(root->left,rest);
         res+=pathSumWithRoot(root->right,rest);
         return res;
     }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}