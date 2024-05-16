class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) 
    {
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    unordered_map<int, ListNode*> sumMap;
    int sum = 0;
    
    sumMap[0] = dummy;
    
    while (head) 
    {
        sum += head->val;
        if (sumMap.find(sum) != sumMap.end()) 
        {
            ListNode* prev = sumMap[sum];
            int currSum = sum;
            ListNode* toRemove = prev->next;
            
            while (toRemove != head) 
            {
                currSum += toRemove->val;
                sumMap.erase(currSum);
                toRemove = toRemove->next;
            }
            
            prev->next = head->next;
        } 
        else 
        {
            sumMap[sum] = head;
        }
        head = head->next;
    }
    
    return dummy->next;

    }
};
