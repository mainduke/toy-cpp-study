//vowel 은 모음이다.
#include <iostream>

using namespace std;

class Solution {
public:
    bool isVowel(char c) {
        string vowels = "aeiouAEIOU";
        return vowels.find(c) != string::npos;
    }

    string reverseVowels(string s) {
        char head = 0;
        char tail = s.size() - 1;
        
        while (head < tail) {
            if (!isVowel(s[head])) head++;
            else if (!isVowel(s[tail])) tail--;
            else {
                swap(s[head], s[tail]);
                head++;
                tail--;
            }
        }

        return s;
    }
};

int main() {
    std::cout << "Hello World" << std::endl;
    Solution sol;


    string result = sol.reverseVowels("IceCreAm");
    
    cout << result << endl;

    return 0;
}