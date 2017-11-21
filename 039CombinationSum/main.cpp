#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;
class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> before;
        _combinationSum(candidates,before,target,0);
        return res;

    }
    void _combinationSum(vector<int> &candidates,vector<int> &before,int rest,int start){
        if(rest==0){
           res.push_back(before);
            return;
        }
        if(rest<0){
            return;
        }
        for(int i = start;i<candidates.size();i++){
            int item = candidates[i];
            before.push_back(item);
            _combinationSum(candidates,before,rest-item,i);
            before.pop_back();
        }
    }
};
int main() {
    vector<int> candidates;
    candidates.push_back(2);
    candidates.push_back(3);
    candidates.push_back(5);
    vector<vector<int>> res = Solution().combinationSum(candidates,8);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}