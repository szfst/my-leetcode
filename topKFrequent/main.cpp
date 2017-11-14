#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

//using priority queue to solve this problem with n log k time complexity
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        vector<int> res;
        int len = nums.size();
        if(len==0){
            return res;
        }
        if(k<=0){
            return res;
        }
        unordered_map<int,int>  mp;

        for(int i = 0;i<len;i++){
            mp[nums[i]]++;
        }
        for(unordered_map<int,int>::iterator itor = mp.begin();itor!=mp.end();itor++){
            if(q.size()==k){
                if(itor->second>q.top().first){
                    q.pop();
                    //let the count of the number to be the first element,in order to make the queue compare the number
                    q.push(make_pair(itor->second,itor->first));
                }
            }else{
                //let the count of the number to be the first element,in order to make the queue compare the number
                q.push(make_pair(itor->second,itor->first));
            }

        }
        while(!q.empty())
        {
            int item = q.top().second;
            q.pop();
            res.push_back(item);
        };
        return res;

    }

};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}