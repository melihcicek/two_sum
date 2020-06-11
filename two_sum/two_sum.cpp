

#include <iostream>
#include <unordered_set>

template<typename T, typename U>
bool get_sum_target(const T& nums, const U& target, std::pair<U, U>& result)
{
    bool target_found = false;
    std::unordered_set<U> added_nums;

    for (const U& r : nums) {
        if (r < target) {
            if (added_nums.find(target - r) != added_nums.end()) {
                result.first = r;
                result.second = target - r;
                target_found = true;
                break;
            }
            added_nums.insert(r);
        }
    }

    return target_found;
}

template<typename T, typename U>
void print_result(const T& nums, const U& target)
{
    auto result = std::make_pair<U, U>(-1, -1);

    if (get_sum_target(nums, target, result)) {
        std::cout << result.first << " " << result.second << "\n";
    }
    else {
        std::cout << "not found !\n";
    }
}


int main()
{
    using namespace std;

    list<int> nums{ 3, 6, 9, 14, 12, 4, 8, 2, 1 };


    print_result(nums, 12);
    print_result(vector<double>{2.0, 5.0, 12.2, 0.1, 0.5, 1.0, 0.6 }, 5.6);

}
