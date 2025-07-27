class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n= nums.size();
        int close = nums[0]+nums[1]+nums[2];
        if(n==3){
            return close;
        }
        for(int i = 0;i<=n-3;i++){
            int l = i+1, r = n-1;
            while(l<r){
                int cur = nums[i]+nums[l]+nums[r];
                if(abs(cur-target)<abs(close-target)){
                    close = cur;
                }
                if(cur==target){
                    return cur;
                }else if(cur>target){
                    r--;
                }else{
                    l++;
                }
            }
        }

        return close;
    }
};