#include <iostream>
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
    int countNodes(TreeNode* root) {
        if(root== nullptr){
            return 0;
        }
        int hl=0,hr=0;
        TreeNode *l = root;
        TreeNode *r = root;
        while(l){
            hl++;l=l->left;
        }
        while(r){
            hr++;r=r->right;
        }
        if(hr==hl){
            return pow(2,hl)-1;
        }
        return countNodes(root->left)+countNodes(root->right)+1;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}