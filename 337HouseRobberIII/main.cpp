#include <iostream>
#include <unordered_map>

using namespace std;
class Solution {
    unordered_map<TreeNode*,int> map;
    struct TreeNode {
          int val;
          TreeNode *left;
          TreeNode *right;
          TreeNode(int x) : val(x), left(NULL), right(NULL) {}
      };
public:
    int rob(TreeNode* root) {
        if(!root)return 0;
        if(!root->left && !root->right)return root->val;
        int d = depth(root,0);
        if(d==2) return max(root->val,getValue(root->left)+getValue(root->right));
        return max(rob(root->left)+rob(root->right),root->val+rob(getChildLeft(root->left))+rob(getChildRight(root->left))+rob(getChildLeft(root->right))+rob(getChildRight(root->right)));
    }
    int getValue(TreeNode* node){
        if(!node)return 0;
        return node->val;
    }
    TreeNode* getChildLeft(TreeNode* node){
        if(!node)return nullptr;
        return node->left;
    }
    TreeNode* getChildRight(TreeNode* node){
        if(!node)return nullptr;
        return node->right;
    }
    int depth(TreeNode* node,int before){
        if(!node) return before;
        return max(depth(node->left,before+1),depth(node->right,before+1));
    }
    int rob2(TreeNode* root) {
        if(!root)return 0;
        if(map.find(root)!=map.end())return map[root];
        if(!root->left && !root->right)return root->val;
        int res;
        if((root->left && root->left->left) || (root->left && root->left->right) ||
           (root->right && root->right->left) || (root->right && root->right->right)){
            res = max(rob(root->left)+rob(root->right),root->val+rob(root->left?root->left->left:nullptr)
                                                       +rob(root->left?root->left->right:nullptr)+rob(root->right?root->right->left:nullptr)
                                                       +rob(root->right?root->right->right:nullptr));
        }else{
            res =  max(root->val,(root->left?root->left->val:0)+(root->right?root->right->val:0));
        }
        map.insert(make_pair(root,res));
        return res;
    }
    //TO DO
    int robDP(TreeNode* root) {
        if(!root)return 0;
        if(map.find(root)!=map.end())return map[root];
        if(!root->left && !root->right)return root->val;
        int res;
        if((root->left && root->left->left) || (root->left && root->left->right) ||
           (root->right && root->right->left) || (root->right && root->right->right)){
            res = max(rob(root->left)+rob(root->right),root->val+rob(root->left?root->left->left:nullptr)
                                                       +rob(root->left?root->left->right:nullptr)+rob(root->right?root->right->left:nullptr)
                                                       +rob(root->right?root->right->right:nullptr));
        }else{
            res =  max(root->val,(root->left?root->left->val:0)+(root->right?root->right->val:0));
        }
        map.insert(make_pair(root,res));
        return res;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}