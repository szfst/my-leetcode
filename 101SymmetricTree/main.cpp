#include <iostream>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if(root== nullptr){
            return true;
        }
        return _isSymmetric(root->left, root->right);

    }
    bool _isSymmetric(TreeNode* p,TreeNode* q){
        if(!p && !q){
            return true;
        }
        if(!p || !q){
            return false;
        }
        //p!=null,q!=null
//        if(!_isSymmetric(p->left,q->right) || !_isSymmetric(p->right,q->left)){
//            return false;
//        }
        return p->val == q->val && _isSymmetric(p->left,q->right) && _isSymmetric(p->right,q->left) ;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}