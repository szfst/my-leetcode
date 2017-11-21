#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;
class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> before;
        _combine(before,n,k,1);
        return res;
    }
    //deliver a reference is more efficient
    void _combine(vector<int> &before,int n,int k,int start){
        if(before.size() == k){
            res.push_back(before);
            return;
        }
        for(int i = start;i<=n;i++){
            before.push_back(i);
            _combine(before,n,k,i+1);
            before.pop_back();
        }
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}