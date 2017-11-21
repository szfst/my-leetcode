#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(!nums.size())return res;
        vector<int> before;
        unordered_set<int> used;
        _permute(nums,0,before,used);
        return res;
    }
    void _permute(vector<int>& nums,int index,vector<int> before,unordered_set<int> used){
        if(index==nums.size()){
            res.push_back(before);
            return;
        }
        for(int i = 0;i<nums.size();i++){
            if(used.find(nums[i])==used.end()){
                used.insert(nums[i]);
                before.push_back(nums[i]);
                _permute(nums,index+1,before,used);
                //backtracking
                used.erase(nums[i]);
                before.pop_back();
            }
        }
    }
};
int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    vector<vector<int>> res = Solution().permute(nums);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}