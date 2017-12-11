#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {

public:
    int coinChange(vector<int>& coins, int amount) {
        int res;
        vector<int> memo;
        memo = vector<int>(amount+1,amount+1);
        memo[0]=0;
        for(int i = 0;i<amount+1;i++){
            for(int j = 0;j<coins.size();j++){
                if(i-coins[j]>=0)
                    memo[i]=min(memo[i],memo[i-coins[j]]+1);
            }
        }
        return memo[amount]==amount+1?-1:memo[amount];
    }


};
int main() {
    vector<int> coins;
    coins.push_back(1);
    coins.push_back(2);
    coins.push_back(5);
    std::cout << "Hello, World!"<<Solution().coinChange(coins,30) << std::endl;
    return 0;
}