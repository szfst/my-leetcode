#include <iostream>
#include <vector>
#include <stack>
#include <cmath>

using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int res = 0;
        if(!root)return 0;
        stack<int> s;
        _sumNumbers(root,s,res);
        return res;
    }
    void _sumNumbers(TreeNode* root,stack<int> path,int &res){
        if(!root)return;
        if(!root->left && !root->right){
            res+=root->val;
            int order = 1;
            while(!path.empty()){
                res+=pow(10,order)*path.top();
                path.pop();
                order++;
            }
            return;
        }
        path.push(root->val);
        _sumNumbers(root->left,path,res);
        _sumNumbers(root->right,path,res);
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}