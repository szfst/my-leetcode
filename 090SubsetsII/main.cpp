#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
    vector<vector<int>> res;
    int size;
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        size = nums.size();
        vector<int> before;
        res.push_back(before);
        _subsetsWithDup(nums,before,0);
        return res;
    }
    void _subsetsWithDup(vector<int>& nums,vector<int> before,int start){
        if(start==size){
            return;
        }
        for(int i = start;i<size;i++){
            if(i>start && nums[i]==nums[i-1])continue;
            before.push_back(nums[i]);
            res.push_back(before);
            _subsetsWithDup(nums,before,i+1);
            before.pop_back();
        }
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}