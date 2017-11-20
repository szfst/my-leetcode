#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
    vector<vector<string>> res;
public:
    vector<vector<string>> partition(string s) {
        vector<string> before;
        _partition(s,before);
        return res;
    }
    void _partition(string s,vector<string> before){
//        cout<<s<<endl;
        if(s.empty()){
            res.push_back(before);
            return;
        }
        if(s.size()==1){
            before.push_back(s);
            res.push_back(before);
            return;
        }
        for(int i = 1;i<s.size()+1;i++){
            string item = s.substr(0,i);
            if(isPalindromeBefore(item)){
                vector<string> b = before;
                b.push_back(item);
                _partition(s.substr(i,s.size()-1),b);
            }
        }

    }
    bool isPalindromeBefore(string s) {
        if(s.empty() || s.size()==1 ){
            return true;
        }
        int i = 0;
        int j = s.size()-1;
        while(i<j){
            if(!isalnum(s[i])){
                i++;
                continue;
            }
            if(!isalnum(s[j])){
                j--;
                continue;
            }
            if(toupper(s[i])!=toupper(s[j])){

                return false;
            }
            i++;
            j--;
        }

        return true;

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
    std::cout << "Hello, World!" << std::endl;
    vector<vector<string>> res = Solution().partition("bb");
    for(int i = 0;i<res.size();i++){
        for(int j = 0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}