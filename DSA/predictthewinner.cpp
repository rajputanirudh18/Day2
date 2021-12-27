class Solution {
public:
    int dp[22][22][22];
    int PredictTheWinnerHelper(vector<int> nums,int i,int j,int chance){
        if(i>j) return 0;
        if(dp[i][j][chance]!=-1) return dp[i][j][chance];
        if(chance==0) return dp[i][j][chance]=max(nums[i]+PredictTheWinnerHelper(nums,i+1,j,1),nums[j]+PredictTheWinnerHelper(nums,i,j-1,1));
        else
            return dp[i][j][chance]= min(PredictTheWinnerHelper(nums,i+1,j,0),PredictTheWinnerHelper(nums,i,j-1,0));
    }
    bool PredictTheWinner(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        int two =0;
        int n=nums.size();
        for(int i=0; i<n; i++)
            two+=nums[i];
        
        int one=PredictTheWinnerHelper(nums,0,n-1,0);
        two-=one;
        return (one>=two);
    }
};