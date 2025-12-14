// T.C = O(n)
// S.C = O(1)
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
    
       int minLength = INT_MAX;
       int i = 0 , j = 0 , sum = 0 , n = nums.size();

        while(j < n){
            sum += nums[j];

            while(sum >= target){
                minLength = min(minLength , j - i + 1 );
                sum -= nums[i];
                i++;
            }
            j++;

        }

        return (minLength == INT_MAX ? 0 : minLength);

    }
};
