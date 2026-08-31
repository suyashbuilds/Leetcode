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
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        
        ListNode* prev = head;
        ListNode* curr = head->next;

        int i = 1;
        int prevcritical = 0;
        int finalcritical = 0;

        int minima = INT_MAX;

        while(curr->next != NULL){

            if((curr->val < prev->val && curr->val < curr->next->val) || (curr->val > prev->val && curr->val > curr->next->val)){

                if(prevcritical == 0){
                    prevcritical = i;
                    finalcritical = i;
                }
                else{
                    minima = min(minima, i - prevcritical);
                    prevcritical = i;
                }
            }
            i++;
            prev = curr;
            curr = curr->next;
        }

        if(minima == INT_MAX){
            return {-1,-1};
        }
        int maxima = prevcritical - finalcritical;
        return {minima, maxima};
    }
};