#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;


class Solution {
public:
    //using priority queue to solve this problem with n log k time complexity
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
        for(auto itor = mp.begin(); itor != mp.end(); itor++){
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
    //using priority queue to solve this problem with n log n-k time complexity
    vector<int> topKFrequent2(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> q;
        vector<int> res;
        unordered_map<int,int>  mp;
        for (int num : nums) {
            mp[num]++;
        }
        for (auto &itor : mp) {
            if(q.size()==mp.size()-k){
                if(!q.empty() && itor.second<q.top().first){
                    res.push_back(q.top().second);
                    q.pop();
                    //let the count of the number to be the first element,in order to make the queue compare the number
                    q.push(make_pair(itor.second, itor.first));
                }else{
                    res.push_back(itor.first);
                }
            }else{
                //let the count of the number to be the first element,in order to make the queue compare the number
                q.push(make_pair(itor.second, itor.first));
            }

        }
        return res;
    }
    //using bucket sort to solve this problem with n  time complexity
    vector<int> topKFrequentBucketSort(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> q;
        vector<int> res;
        //frequency may equal to the size of the nums,so bucket size should be nums.size()+1;
        vector<vector<int>> bucket(nums.size()+1);
        unordered_map<int,int>  mp;
        for (int num : nums) {
            mp[num]++;
        }
        for (auto &iter : mp) {
            int frequency = iter.second;
            bucket[frequency].push_back(iter.first);
        }
        for(int pos = bucket.size()-1;res.size()<k;pos--){
            res.insert(res.end(),bucket[pos].begin(),bucket[pos].end());
        }
        return res;
    }

};
int main() {
    int nums[] = {1};
    vector<int> vec( nums, nums + sizeof(nums)/sizeof(int));
    int k = 1;

    vector<int> res = Solution().topKFrequent2(vec,k);
    for( int i = 0 ; i < res.size() ; i ++ )
        cout<<res[i]<<" ";
    cout<<endl;

    return 0;
}