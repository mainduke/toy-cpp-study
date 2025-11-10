#include <iostream>
#include <vector>

class Soultuion {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int i = m - 1; // nums1의 마지막 유효 요소 인덱스
        int j = n - 1; // nums2의 마지막 요소 인덱스
        int k = m + n - 1; // 병합된 배열의 마지막 인덱스

        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }

        // nums2에 남은 요소가 있다면 복사
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}