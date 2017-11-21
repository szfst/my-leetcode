#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
    //this code run 6ms and beats 87.4% c++ code
    vector<vector<int>> res;
    int size =  0;
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> before;
        //define the size at first to faster the code
        size = candidates.size();
        combinationSum2(candidates,target,before,0);

        return res;

    }
    void combinationSum2(vector<int>& candidates, int target,vector<int> &before,int start){
        if(target==0){
            res.push_back(before);
            return;
        }
        if(target<0){
            return;
        }
        for(int i = start;i<size;i++){
            //define the item at first to faster the code
            int item = candidates[i];
            if(i>start &&  item==candidates[i-1])continue;
            before.push_back(item);
            combinationSum2(candidates,target-item,before,i+1);
            before.pop_back();
        }
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}