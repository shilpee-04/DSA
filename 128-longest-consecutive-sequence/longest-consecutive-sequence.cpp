class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n= nums.size();
        if(n==0) return 0;
        unordered_set<int> st;
        for(auto it: nums) st.insert(it);

        int maxlen=1;
        
       
        for(auto it:st){
            if(st.find(it-1) == st.end()){
      
                int len=1;
                int el = it;
                while(st.find(el+1)!=st.end()){
                    len++;
                    el++;
                }
                
                maxlen=max(len,maxlen);
             
            }
        }
        return maxlen;
        
    }
};