#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size==0)return 0;
        if(size==1)return nums[size-1];
        vector<int> res(size,-1);
        res[size-1]=nums[size-1];
        res[size-2]=max(nums[size-1],nums[size-2]);
        for(int i = size-3;i>=0;i--){
            res[i]=max(res[i+1],nums[i]+res[i+2]);
        }
        return res[0];
    }
};

int main() {
    vector<int> nums= {0,0,0};
    std::cout << "Hello, World!"<<Solution().rob(nums) << std::endl;
    return 0;
}