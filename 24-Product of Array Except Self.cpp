class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> prefixProducts(n);
    vector<int> suffixProducts(n);
    vector<int> answer(n);

    // Calculate prefix products
    prefixProducts[0] = 1;
    for (int i = 1; i < n; ++i) {
        prefixProducts[i] = prefixProducts[i - 1] * nums[i - 1];
    }

    // Calculate suffix products
    suffixProducts[n - 1] = 1;
    for (int i = n - 2; i >= 0; --i) {
        suffixProducts[i] = suffixProducts[i + 1] * nums[i + 1];
    }

    // Calculate answer
    for (int i = 0; i < n; ++i) {
        answer[i] = prefixProducts[i] * suffixProducts[i];
    }

    return answer;
}

int main() {
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> result1 = productExceptSelf(nums1);
    cout << "Output for [1, 2, 3, 4]: ";
    for (int num : result1) {
        cout << num << " ";
    }
    cout << endl;

    vector<int> nums2 = {-1, 1, 0, -3, 3};
    vector<int> result2 = productExceptSelf(nums2);
    cout << "Output for [-1, 1, 0, -3, 3]: ";
    for (int num : result2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;

    }
};
