#include <iostream>
#include <vector>
#include <unordered_map>
#include <time.h>

using namespace std;

class Solution {
    vector<vector<vector<int>>> memo;
    int size;
public:
    int findMaxForm3(vector<string>& strs, int m, int n) {
        //定义的数组开头是，不取，取第一个，取第二个，所以一共有strs.size()+1这么多种情况
        vector<vector<vector<int>>> memo1 = vector<vector<vector<int>>>(strs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,0)));
        for(int i = 0;i<strs.size()+1;i++){
            vector<int> mn =vector<int>(2,0);
            //如果都不取，则消耗的0,1 都为0，如果取第一个，消耗的01 为数组的开头，即为strs[0]
            if(i>0) mn = calculateMN(strs[i-1]);

            for(int j = 0;j<m+1;j++){
                for(int k = 0;k<n+1;k++){

                    if(i == 0){
                        memo1[i][j][k]=0;
                    }else{
                        if(j-mn[0]>=0 && k-mn[1]>=0){
                            memo1[i][j][k] = max(memo1[i-1][j][k],memo1[i-1][j-mn[0]][k-mn[1]]+1);
                        }else{
                            memo1[i][j][k]= memo1[i-1][j][k];
                        }
                    }
                }
            }
        }
        return memo1[strs.size()][m][n];
    }
//    int findMaxForm(vector<string>& strs, int m, int n) {
//        int a = 0;
//        int b = 0;
//        for(int i = 0;i<strs.size();i++){
//            for(int j = 0;j<strs[i].size();j++){
//                if(strs[i][j]=='0'){
//                    a++;
//                }else{
//                    b++;
//                }
//            }
//        }
//        size = strs.size();
//        m = min(m,a);
//        n = min(n,b);
//        memo = vector<vector<vector<int>>>(strs.size()+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
//        return tryForm(strs,m,n,0);
//    }
//    int tryForm(vector<string>& strs, int m, int n,int index){
//        if(index==size)return 0;
//        if(memo[index][m][n]!=-1)return memo[index][m][n];
//        int res = 0;
//        vector<int> mn = calculateMN(strs[index]);
//        for(int i=0;i<m+1;i++){
//            for(int j = 0;j<n+1;j++){
//                if(index+1<size){
//                    if(memo[index+1][i][j]!=-1){
//                       res = memo[index+1][i][j];
//                    }else{
//                        res = tryForm(strs,i,j,index+1);
//                        memo[index+1][i][j]=res;
//                    }
//                }
//                if(i-mn[0]>=0 && j-mn[1]>=0){
//                    int next2 = tryForm(strs,i-mn[0],j-mn[1],index+1)+1;
//                    if(index+1<size)memo[index+1][i-mn[0]][j-mn[1]]=next2;
//                     res = max(res,next2);
//                }
//            }
//        }
//        memo[index][m][n]=res;
//        return res;
//    }
    vector<int> calculateMN(string s){
        vector<int> res(2,0);
        for(int k = 0;k<s.size();k++){
            if(s[k]=='0'){
                res[0]++;
            }else{
                res[1]++;
            }
        }
        return res;
    }
    int findMaxForm2(vector<string>& strs, int m, int n) {
        vector<vector<int>> memo(m+1, vector<int>(n+1, 0));
        int numZeroes, numOnes;

        for (auto &s : strs) {
            numZeroes = numOnes = 0;
            // count number of zeroes and ones in current string
            for (auto c : s) {
                if (c == '0')
                    numZeroes++;
                else if (c == '1')
                    numOnes++;
            }

            // memo[i][j] = the max number of strings that can be formed with i 0's and j 1's
            // from the first few strings up to the current string s
            // Catch: have to go from bottom right to top left
            // Why? If a cell in the memo is updated(because s is selected),
            // we should be adding 1 to memo[i][j] from the previous iteration (when we were not considering s)
            // If we go from top left to bottom right, we would be using results from this iteration => overcounting
            for (int i = m; i >= numZeroes; i--) {
                for (int j = n; j >= numOnes; j--) {
                    memo[i][j] = max(memo[i][j], memo[i - numZeroes][j - numOnes] + 1);
                }
            }
        }
        return memo[m][n];
    }

};

int main() {
    vector<string> strs={"10","0","1"};
    clock_t startTime = clock();
    std::cout << "Hello, World!"<<Solution().findMaxForm3(strs,1,1) << std::endl;
    clock_t endTime = clock();
    cout << double(endTime - startTime) / CLOCKS_PER_SEC << " s" << endl;
    return 0;
}