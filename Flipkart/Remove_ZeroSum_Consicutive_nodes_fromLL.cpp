#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* root = new ListNode(0);
        root->next = head;

        unordered_map<int, ListNode*> mp;
        mp[0] = root;
        int prefix = 0;

        while(head != NULL){
            prefix += head->val;

            if(mp.count(prefix)){
                ListNode* prev = mp[prefix];
                ListNode* curr = prev;

                int temp = prefix;
                while(prev != head){
                    prev = prev->next;
                    temp += prev->val;
                    if(prev != head)
                        mp.erase(temp);
                }
                curr->next = head->next;
            }
            else{
                mp[prefix] = head;
            }
            head = head->next;
        }

        return root->next;
    }
};