class Solution {
public:
    int pivotInteger(int n) {
    int totalSum = n * (n + 1) / 2;
    int prefixSum = 0;

    for (int i = 1; i <= n; ++i) {
        prefixSum += i;
        if (prefixSum == totalSum - prefixSum + i) {
            return i; 
        }
    }

    return -1; 
}

int main() {
    int n1 = 8, n2 = 1, n3 = 4;
    cout << "Pivot for n = 8: " << pivotInteger(n1) << endl;
    cout << "Pivot for n = 1: " << pivotInteger(n2) << endl;
    cout << "Pivot for n = 4: " << pivotInteger(n3) << endl;
    return 0;
}

    
};
