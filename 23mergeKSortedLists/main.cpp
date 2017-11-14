#include <iostream>
#include <vector>
#include <queue>

using namespace std;
//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
    struct cmp
    {
        bool operator()(ListNode *a,ListNode *b) { return  a->val > b->val; }
    };
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,cmp> pq;
        for(auto &item:lists){
            if(item){
                pq.push(item);
            }
        }
        if(pq.empty()){
            return nullptr;
        }
        auto dummyHead = new ListNode(0);
        ListNode* head = dummyHead;
        //every time ,find the min element
        while(!pq.empty()){
            //find the head of the list;
            head->next = pq.top();
            pq.pop();
            head=head->next;
            //if next of the head exist,put to pq
            if(head->next){
                pq.push(head->next);
            }
        }
        return dummyHead->next;
    }
};
int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}