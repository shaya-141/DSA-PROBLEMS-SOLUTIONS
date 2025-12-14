class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        int n = arr.size() , i = 0 , j = 0;
        deque<int> dq;
        vector<int> ans;
        while(j  <  n){
            if(arr[j] < 0) dq.push_back(arr[j]);
            
            if(j - i + 1 > k) {
                if(arr[i] < 0) dq.pop_front();
                i++;
            }
            
            if(j - i + 1 == k) {
                if(dq.empty()) ans.push_back(0);
                else ans.push_back(dq.front()); 
                
            }
            j++;
            
        }
        
        return ans;
        
    }
};
