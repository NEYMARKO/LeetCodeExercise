class Solution {
public:
    int hammingWeight(int n) {
        int set_bit_cnt = 0;
        while (n > 0)
        {
            if (n % 2 == 1)
            {
                set_bit_cnt++;
            }
            n /= 2;
        }
        return set_bit_cnt;
    }
};