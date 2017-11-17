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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //in a binary search,all the left nodes is smaller or equal to root,all the right nodes is bigger or equal to root
        if(root->val>p->val && root->val>q->val){
            return lowestCommonAncestor(root->left,p,q);
        }
        if(root->val<p->val && root->val<q->val){
            return lowestCommonAncestor(root->right,p,q);
        }
        //p<=root,q>=root,if p==root,p is lca,root is also lca;if q==root,q is lca,root is also lca;
        // if p<root,q>root,root is lca;so root is lca in this three cases
        return root;
    }
    TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val>q->val){
            swap(p,q);
        }
        return _lowestCommonAncestor(root, p, q);

    }
    TreeNode* _lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        //in a binary search,all the left nodes is smaller or equal to root,all the right nodes is bigger or equal to root
        //if root>q,than root>q,because p<q;
        if(root->val>q->val){
            return _lowestCommonAncestor(root->left,p,q);
        }
        //if root<q,than root<p,because p<q
        if(root->val<p->val){
            return _lowestCommonAncestor(root->right,p,q);
        }
        //p<=root,q>=root,if p==root,p is lca,root is also lca;if q==root,q is lca,root is also lca;
        // if p<root,q>root,root is lca;so root is lca in this three cases
        return root;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}