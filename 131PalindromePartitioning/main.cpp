#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {

    }
    bool isPalindrome(string s){
        if(s.size()==1){
            return true;
        }
        stack<char> stackPush;
        int mid = s.size()/2;
        for(int i = 0;i<mid;i++){
            stackPush.push(s[i]);
        }
        string rest;
        if(s.size()%2==1){
            rest= s.substr(mid,s.size());
        }else{
            rest = s.substr(mid+1,s.size());
        }
        int iter = 0;
        while(!stackPush.empty()){
            if(stackPush.top()!=rest[iter]){
                return false;
            }
            stackPush.pop();
            iter++;
        }
        return iter == rest.size();
    }
};

int main() {
    std::cout << "Hello, World!" <<Solution().isPalindrome("aba")<< std::endl;
    return 0;
}