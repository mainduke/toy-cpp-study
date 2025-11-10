#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        cout << "insert str = \"" << s << "\"" << endl;
        string result = "";
        stack<string> wordStack;
        int len = s.length();
        
        int i = 0;
        string temp = "";
        char last = 0;

        if (s[0] == ' ') i++;

        cout << "str length = " << len << endl;
        while (i < len) {
            if (s[i] != ' ') {
                temp += s[i];
                // 마지막 문자열일 경우, temp 삽입
                if (i == (len-1)) wordStack.push(temp);
            }

            // 두칸 ' ' 체크
            // 마지막 문자열이 ' '일 경우, "" 삽입이 일어남 방지
            if (last != ' ' && s[i] == ' ' && temp != "") {
                wordStack.push(temp);
                temp.clear();    
            } 

            last = s[i];
            i++;
        }
        
        while (!wordStack.empty()) {
            cout << "\"" << wordStack.top() << "\"" << endl;
            result += wordStack.top();
            wordStack.pop();
            if (!wordStack.empty()) result += " ";
        }

        return result;
    }
};

int main() {
    string str = "  hello world  ";

    Solution sol;
    string result = sol.reverseWords(str);
    
    cout << "result = \"" << result << "\"" << endl;

    return 0;
}