class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
    unordered_map<int, int> prefixSumFreq;
    int currSum = 0, count = 0;

    for (int num : nums) {
        currSum += num;
        if (prefixSumFreq.count(currSum - goal)) {
            count += prefixSumFreq[currSum - goal];
        }
        if (currSum == goal) {
            count++; 
        }
        prefixSumFreq[currSum]++;
    }

    return count;
}

int main() {
    vector<int> nums1 = {1, 0, 1, 0, 1};
    int goal1 = 2;
    cout << "Number of subarrays with sum " << goal1 << ": " << numSubarraysWithSum(nums1, goal1) << endl;

    vector<int> nums2 = {0, 0, 0, 0, 0};
    int goal2 = 0;
    cout << "Number of subarrays with sum " << goal2 << ": " << numSubarraysWithSum(nums2, goal2) << endl;

    return 0;
}
};
