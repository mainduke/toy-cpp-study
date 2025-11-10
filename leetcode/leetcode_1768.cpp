#include <iostream>

using namespace std;

class Solution {
    public:
        string mergeAlternately(string word1, string word2) {
            string result;
            int i = 0;
            
            while (word1.size() > i && word2.size() > i) {
                result += word1[i];
                result += word2[i];
                i++;
            }

            if (word1.size() > word2.size()) {
                while (i < word1.size()) {
                    result += word1[i++];
                }
            } else {
                while (i < word2.size()) {
                    result += word2[i++];
                }
            }
            
            return result;
        }
};

int main () {
    std::cout << "Hello World" << std::endl;
    return 0;
}