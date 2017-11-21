#include <iostream>
#include <vector>

using namespace std;
class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> before;
        combinationSum3(k,n,before,1);
        return res;

    }
    void combinationSum3(int k, int n,vector<int> &before,int start){
        if(n==0){
            if(before.size()==k){
                res.push_back(before);
            }
            return;
        }
        if(n<0){
            return;
        }
        for(int i = start;i<=9;i++){
            before.push_back(i);
            combinationSum3(k,n-i,before,i+1);
            before.pop_back();
        }
    }
};
int main() {
    Solution().combinationSum3(3,9);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}