#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    string gcdOfStrings(string str1, string str2) {
        if (str1 + str2 != str2 + str1) {
            return "";
        }
        int gcd_length = gcd(str1.size(), str2.size());
        return str1.substr(0, gcd_length);
    }
};

int main() {
    std::cout << "Hello, LeetCode!" << std::endl;
    
    Solution sol;

        std::string str1 = "ABABAB";
        std::string str2 = "ABAB";
        std::string result = sol.gcdOfStrings(str1, str2);
        std::cout << "GCD of strings: " << result << std::endl; 
    
    return 0;
}
