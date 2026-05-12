class Solution {
public:
    int getSum(int a, int b) {
        int carry, sum;
        do {
            carry = a & b;
            sum = a ^ b;
            a = carry << 1;
            b = sum;
        } while (carry != 0);
        return sum;
    }
};
