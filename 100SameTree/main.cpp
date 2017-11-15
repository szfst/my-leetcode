#include <iostream>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p== nullptr && q== nullptr){
            return true;
        }
        if(p== nullptr || q== nullptr){
            return false;
        }
        //p!=null,q!=null
        if(!isSameTree(p->left,q->left) || !isSameTree(p->right,q->right) ){
            return false;

        }
        return p->val == q->val;

    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}