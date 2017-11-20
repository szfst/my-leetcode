#include <iostream>
#include <vector>

using namespace std;
class Solution {
    vector<string> res;
    vector<string> digitsToString = {" ","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
public:
    vector<string> letterCombinations(string digits) {
        string before;
        if(digits.empty()){
            return res;
        }
        combineDigits(digits,0,before);
        return res;
    }
    void combineDigits(string &digits,int index,string before){
        if(index==digits.size()){
            res.push_back(before);
            return;
        }
        char c = digits[index];
        int digit  = c-'0';
        string value = digitsToString[digit];
        for (char i : value) {
            combineDigits(digits,index+1,before+i);
        }
    }
};
int main() {
    string dig = "123";
   vector<string> res =  Solution().letterCombinations("23");
    for(int i = 0;i<res.size();i++){
        cout<<res[i]<<endl;
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}