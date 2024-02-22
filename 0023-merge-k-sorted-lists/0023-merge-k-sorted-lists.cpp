/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// class Node{
    
//     int val;
//     Node* next;
//     public:
//         Node(int value){
//             val = value;
//             next = nullptr;
//         }  
// };

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // approach 
        // first store first node of every list in priority-queue
        // then we will get min val and will push its next to pq and connect current to list in this way we will get sorted list
        
        // making min heap
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> pq;
        
        for(int i=0; i<lists.size(); i++){
            if(lists[i]){
                pq.push({lists[i]->val, lists[i]});
            }
            
        }
        
        ListNode* dummy = new ListNode(-1);
        ListNode* temp = dummy;
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            ListNode* node = it.second;
            temp->next = node;
            
            if(node->next){
                pq.push({node->next->val, node->next});
            }
            
            temp=temp->next;
        }
        return dummy->next;
    }
};
















