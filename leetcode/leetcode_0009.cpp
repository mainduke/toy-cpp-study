#include <iostream>
#include <cstdint>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        if (x % 10 == 0 && x != 0) return false;
        
        int reversed = 0;

        while (x > reversed) {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }

        return x == reversed || x == reversed / 10;
    }
};

int main() {
    Solution sol;
    int num;
    std::cout << "Enter an integer: ";
    std::cin >> num;
    if (sol.isPalindrome(num))
        std::cout << num << " is a palindrome.\n";
    else
        std::cout << num << " is not a palindrome.\n";
    return 0;
}