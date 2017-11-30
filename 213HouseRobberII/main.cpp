#include <iostream>
#include <vector>

using namespace std;
class Solution {
    int startRob(vector<int>& nums) {
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
public:
    //no matter where you start,you get the same house you rob;
    //because the houses are arrange in circle,so if you rob the first house,
    //you can not rob the last house,vice versa.
    // so the solution is max(rob(nums,l,r-1),rob(nums,l-1,r))
    int rob(vector<int>& nums){
        int size = nums.size();
        if(size==0)return 0;
        if(size==1)return nums[size-1];
        vector<int> sub1;
        vector<int> sub2;
        for(int i = 1;i<size;i++){
            sub1.push_back(nums[i]);
            sub2.push_back(nums[i-1]);
        }
        return max(startRob(sub1),startRob(sub2));
    }
};
int main() {
    vector<int> nums = {1,1,1};

    std::cout << "Hello, World!"<<Solution().rob(nums) << std::endl;
    return 0;
}