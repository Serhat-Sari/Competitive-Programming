class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        else if(nums.size() == 1)
            return 1;
        else{
        set<int> st;
        for(int i = 0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        int curr_consec = 1;
        int max_consec = 1;
        set<int>::iterator it1 = st.begin();
        set<int>::iterator it2 = it1;
        it2++;

        while(it2 != st.end()){

            if(*it2 == (*it1) + 1){
                curr_consec++;
                max_consec = max(curr_consec,max_consec);}
            
            else if(*it2 != (*it1) +1 ){
                curr_consec = 1;
            }

            it1++;
            it2++;

        }
        return max_consec;
        }
    }
};