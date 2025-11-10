#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int find_num(string s, map<string, int> romanMap) {
    int result = 0;
    for (int i = 0; i < s.size(); i++) {
        int curr = romanMap[string(1, s[i])];
        int next = (i + 1 < s.size()) ? romanMap[string(1, s[i + 1])] : 0;
        if (curr < next) {
            result -= curr;
        } else {
            result += curr;
        }
    }
    return result;
}

string toRoman(int num) {
    vector<pair<int, string>> roman = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"},  {90, "XC"},  {50, "L"},  {40, "XL"},
        {10, "X"},   {9, "IX"},   {5, "V"},   {4, "IV"},
        {1, "I"}
    };
    string result;
    for (auto &p : roman) {
        while (num >= p.first) {
            result += p.second;
            num -= p.first;
        }
    }
    return result;
}

int main() {

    std::map<std::string, int> romanMap;
    romanMap["I"] = 1;    
    romanMap["V"] = 5;    
    romanMap["X"] = 10;    
    romanMap["L"] = 50;    
    romanMap["C"] = 100;    
    romanMap["D"] = 500;    
    romanMap["M"] = 1000;

    string s1 = "DLIII";
    string s2 = "MCMXL";

    int r1 = find_num(s1, romanMap);
    int r2 = find_num(s2, romanMap);

    int result = r1 + r2;

    string r3 = toRoman(result);

    std::cout << s1 << " = "<< r1 << std::endl;
    std::cout << s2 << " = "<< r2 << std::endl;
    std::cout << result << " = "<< r3 << std::endl;

    return 0;
}