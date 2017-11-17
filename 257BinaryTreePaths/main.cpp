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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(!root)return res;
        string value = to_string(root->val);
        //if the root is leaf
        if(!root->left && !root->right){
            res.push_back(value);
            return res;
        }
        vector<string> leftR = binaryTreePaths(root->left);
        vector<string> rightR = binaryTreePaths(root->right);
        for(const string &item:leftR){
            res.push_back(value+"->"+item);
        }
        for(const string &item:rightR){
            res.push_back(value+"->"+item);
        }

        return res;
    }
};
int main() {
    TreeNode *t1 = new TreeNode(0);
    TreeNode *t2 = new TreeNode(0);
    TreeNode *t3 = new TreeNode(0);
    TreeNode *t5 = new TreeNode(0);
    t1->val = 1;
    t2->val = 2;
    t3->val = 3;
    t5->val = 5;

    t1->left = t2;
    t1->right = t3;
    t2->right = t5;
    Solution().binaryTreePaths(t1);

    std::cout << "Hello, World!" << std::endl;
    return 0;
}