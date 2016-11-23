#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

class solution {
  public:
    void nextPermutation(std::vector<int> & nums) {
        size_t lastmax = findLastLocalmax(nums);
        if (lastmax == 0) {
            std::sort(nums.begin(), nums.end());
        }
        else if (lastmax > 0){
            size_t idx, curr = lastmax;
            while (curr < nums.size()) {
                if (nums[curr] > nums[lastmax-1])
                    idx = curr;
                curr++;
            }
            std::swap(nums[lastmax-1], nums[idx]);
            std::sort(nums.begin()+lastmax, nums.end());
        }
    }

  private:
    size_t findLastLocalmax(const std::vector<int> & nums) {
        size_t idx;
        idx = nums.size()-1;
        while (idx > 0 && nums[idx] < nums[idx-1])
            idx--;
        return idx;
    }
};

int main() {
    std::vector<int> nums{1,2,3,4};
    std::cout << "Before permutation:\n";
    std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;
    
    solution soln;
    std::cout << "After permutation:\n";
    for (int i = 0; i < 30; i++) {
        soln.nextPermutation(nums);
        // std::cout << "After permutation:\n";
        std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(std::cout, " "));
        std::cout << std::endl;
    }
}
