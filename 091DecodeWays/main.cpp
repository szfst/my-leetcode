#include <iostream>
#include <unordered_map>

using namespace std;
class Solution {
    unordered_map<string,int> memo;
public:
    int numDecodings(string s) {
        if(s.empty() || s[0]=='0')return 0;
        if(s.size()==1)return 1;
        if(s.size()==2){
            if(s[0]>='3' && s[1]!='0')return 1;
            if(s[0]>='3' && s[1]=='0')return 0;
            if(s[0]=='2' && s[1]>'6')return 1;
            if(s[1]=='0')return 1;
            return 2;
        }
        if(memo.find(s)!=memo.end()) return memo[s];
        memo[s] = numDecodings(s.substr(1,s.size()-1))+(isVaild(s.substr(0,2))?numDecodings(s.substr(2,s.size()-1)):0);
        return memo[s];
    }
    bool isVaild(string s){
        return ((s[0]-48)*10+(s[1]-48))<=26;
    }
};
int main() {
    std::cout << "Hello, World!" <<Solution().numDecodings("611")<< std::endl;
    return 0;
}