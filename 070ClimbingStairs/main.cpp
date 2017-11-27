#include <iostream>
#include <vector>

using namespace std;
class Solution {
    vector<int> res;
public:
    int climbStairs(int n) {
        res = vector<int>(n+1,-1);
        res[0]=1;
        res[1]=1;
        for(int i = 2;i<=n;i++){
            res[i]=res[i-1]+res[i-2];
        }
        return res[n];
    }
};
int main() {
    std::cout << "Hello, World!" <<Solution().climbStairs(10)<<std::endl;
    return 0;
}