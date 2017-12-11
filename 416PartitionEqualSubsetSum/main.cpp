#include <iostream>
#include <vector>

using namespace std;

class Solution {

public:
    bool canPartition(vector<int>& nums) {
        int size = nums.size();
        int mid = 0;
        for(int i = 0;i<size;i++){
            mid+=nums[i];
        }
        if(mid%2!=0)return false;
        mid = mid/2;
        vector<vector<int>> memo = vector<vector<int>>(size,vector<int>(mid+1,-1));
        for(int i = 0;i<=mid;i++){
            if(nums[0]==i){
                memo[0][i]=1;
            }else{
                memo[0][i]=0;
            }
        }
       for(int i = 1;i<size;i++){
           for(int j = 0;j<=mid;j++){
               memo[i][j]=memo[i-1][j];
               if(j>=nums[i]){
                   memo[i][j]= (memo[i][j] || memo[i-1][j-nums[i]]);
               }
           }
       }
        return memo[size-1][mid]==1;
    }
    //using 2*mid space
    bool canPartition2(vector<int>& nums) {
        int size = nums.size();
        int mid = 0;
        for(int i = 0;i<size;i++){
            mid+=nums[i];
        }
        if(mid%2!=0)return false;
        mid = mid/2;
        vector<vector<int>> memo = vector<vector<int>>(size,vector<int>(mid+1,-1));
        for(int i = 0;i<=mid;i++){
            if(nums[0]==i){
                memo[0][i]=1;
            }else{
                memo[0][i]=0;
            }
        }
        for(int i = 1;i<size;i++){
            for(int j = 0;j<=mid;j++){
                memo[i%2][j]=memo[(i-1)%2][j];
                if(j>=nums[i]){
                    memo[i%2][j]= (memo[i%2][j] || memo[(i-1)%2][j-nums[i]]);
                }
            }
        }
        return memo[(size-1)%2][mid]==1;
    }
    //using mid space
    bool canPartition3(vector<int>& nums) {
        int size = nums.size();
        int mid = 0;
        for(int i = 0;i<size;i++){
            mid+=nums[i];
        }
        if(mid%2!=0)return false;
        mid = mid/2;
        vector<bool> memo(mid+1,false);
        for(int i = 0;i<=mid;i++){
            memo[i]= nums[0] == i;
        }
        for(int i = 1;i<size;i++){
            for(int j = mid;j>=0;j--){
                if(j>=nums[i])memo[j]= (memo[j] || memo[j-nums[i]]);
            }
        }
        return memo[mid];
    }
    //using mid space,cut branch
    bool canPartition4(vector<int>& nums) {
        int size = nums.size();
        int mid = 0;
        for(int i = 0;i<size;i++){
            mid+=nums[i];
        }
        if(mid%2!=0)return false;
        mid = mid/2;
        vector<bool> memo(mid+1,false);
        for(int i = 0;i<=mid;i++){
            memo[i]= nums[0] == i;
        }
        for(int i = 1;i<size;i++){
            for(int j = mid;j>=nums[i];j--){
               memo[j]= (memo[j] || memo[j-nums[i]]);
            }
        }
        return memo[mid];
    }
};
int main() {
    vector<int> nums;
    nums.push_back(100);
//    nums.push_back(2);
//    nums.push_back(3);
//    nums.push_back(5);
    std::cout << "Hello, World!" <<Solution().canPartition3(nums)<< std::endl;
    return 0;
}