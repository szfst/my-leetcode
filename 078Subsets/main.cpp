#include <iostream>
#include <vector>

using namespace std;
class Solution {
    int size;
    vector<vector<int>> res;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        size = nums.size();
        vector<int> before;
        res.push_back(before);
        _subsets(nums,before,0);
        return res;
    }
    void _subsets(vector<int>& nums,vector<int> before,int start){
        if(start==size){
            return;
        }
        for(int i = start;i<size;i++){
            before.push_back(nums[i]);
            res.push_back(before);
            _subsets(nums,before,i+1);
            before.pop_back();
        }
    }
};
int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    Solution().subsets(nums);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}