#include <iostream>
#include <vector>

using namespace std;
class Solution {
    vector<int> res;
public:
    int integerBreak(int n) {
        if(n==0 || n==1)return 0;
        res=vector<int>(n+1,-1);
        res[0]=1;
        res[1]=1;
        tryBreak(n);
        return  res[n];
    }
    int integerBreakDP(int n) {
        if(n==0 || n==1)return 0;
        res=vector<int>(n+1,-1);
        res[0]=1;
        res[1]=1;
        for(int i = 2;i<=n;i++){
            for(int j = 1;j<i;j++){
                res[i]=max3((i-j)*(j),res[i],j*res[i-j]);
            }
        }
        return  res[n];
    }
    int tryBreak(int n){
        if(res[n]!=-1){
            return res[n];
        }
        for(int j = 1;j<n;j++){
            res[n]=max3((n-j)*(j),res[n],j*tryBreak(n-j));
        }
        return res[n];
    }
    int max3(int a,int b,int c){
        return max(a,b)>c?max(a,b):c;
    }
};
int main() {
    std::cout << "Hello, World!"<<Solution().integerBreakDP(10) << std::endl;
    return 0;
}