class Solution {
  public:
    // Complete this function
    // Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(vector<int>& arr) {
        // Your code here
        unordered_set<int>st;
        int sum = 0;
        int n = arr.size();
        for(int i=0; i<n; i++){
            sum += arr[i];
            
            if(sum==0 || st.find(sum)!=st.end()){
                return true;
            }
            
            st.insert(sum);
        }
        
        return false;
    }
};