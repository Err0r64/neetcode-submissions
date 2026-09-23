class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int len = nums.size();
        vector<int> output(len);
        vector<int> prefix(len);
        vector<int> suffix(len);
        // Prefix setup
        int prefixProduct = 1;
        for (int i = 0; i < len; i++) {
            prefixProduct *= nums[i];
            prefix[i] = prefixProduct;
        }

        // Suffix setup
        int suffixProduct = 1;
        for (int i = len - 1; i >= 0; i--) {
            suffixProduct *= nums[i];
            suffix[i] = suffixProduct;
        }


        for (int i = 0; i < len; i++) {
            int p = (i - 1 >= 0) ? prefix[i - 1] : 1;
            int s = (i + 1 < len) ? suffix[i + 1] : 1;

            output[i] = p * s;
        }
        return output;
    }
};
