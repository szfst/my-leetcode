#include <iostream>
#include <vector>

using namespace std;
class Solution {
    vector<int> memo;

public:
    int combinationSum4(vector<int>& nums, int target) {
        memo = vector<int>(target+1,0);
        memo[0]=1;
        for(int i=1;i<target+1;i++){
            for(int j = 0;j<nums.size();j++){
                if(i>=nums[j]){
                    memo[i]+=memo[i-nums[j]];
                }
            }
        }
        return memo[target];
    }
    int combinationSum42(vector<int>& nums, int target) {
        memo = vector<int>(target+1,-1);
        return tryCom(nums,target);
    }
    int tryCom(vector<int>& nums,int target){
        if(target==0)return 1;
        if(memo[target]!=-1)return memo[target];
        int res = 0;
        for(int i = 0;i<nums.size();i++){
            if(target>=nums[i]){
                res += tryCom(nums,target-nums[i]);
            }
        }
        memo[target]=res;
        return res;
    }
};
int main() {
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    std::cout << "Hello, World!" <<Solution().combinationSum4(nums,4)<< std::endl;
    return 0;
}