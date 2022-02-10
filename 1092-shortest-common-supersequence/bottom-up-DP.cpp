//Question Link --> https://leetcode.com/problems/shortest-common-supersequence/

class Solution {
public:
    int dp[1005][1005];
    
    string shortestCommonSupersequence(string str1, string str2) {
        
        int n1=str1.size(), n2=str2.size();
        
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                
                if( str1[i-1] == str2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        string res="";
        int i=n1,j=n2;
        
        while(i>0 and j>0){
            
            if(str1[i-1] == str2[j-1]){
                res.push_back(str1[i-1]);
                i--,j--;
            }
            else if(dp[i-1][j] > dp[i][j-1])
                res.push_back(str1[i-1]),i--;
            else
                res.push_back(str2[j-1]),j--;  
        }
        
        while(i>0) res.push_back(str1[i-1]),i--;
        while(j>0) res.push_back(str2[j-1]),j--;
        
        reverse(res.begin(),res.end());
        
        return res;
        
    }
};
