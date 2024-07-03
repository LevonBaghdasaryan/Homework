#include <iostream>
#include <vector>

int subsetXORSum(std::vector<int>& nums) {
    int size = nums.size();
    int subsetCount = 1 << size;
    int sum = 0;
    
    for (int i = 0; i < subsetCount; ++i) {
        int currentXor = 0;
        for (int j = 0; j < size; ++j) {
            if (i & (1 << j)) {
                currentXor ^= nums[j];
            }
        }
        sum += currentXor;
    }
    return sum;
}

int main() {
    
    std::vector<int> v1 = {1, 3};
    std::vector<int> v2 = {5, 1, 6};
    std::vector<int> v3 = {3,4,5,6,7,8};
    
    std::cout << subsetXORSum(v1) << std::endl;
    std::cout << subsetXORSum(v2) << std::endl;
    std::cout << subsetXORSum(v3) << std::endl;

    return 0;
}