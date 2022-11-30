 #include <iostream>
 using namespace std;
 
 int main()
 {
    int e1=8;  
       int e2=6;  
       int x1=12;  
       int x2=2;  
       int n=6; // number of stations  
       int t[6][6]={{12,5,7,6,12,4},{7,11,3,2,15,9}};  
        
       int trans[5][5]={{2,4,6,10,8},{1,3,5,9,7}};  
         
       int dp[2][n];  
       dp[0][n-1]=t[0][n-1]+x1;  
       dp[1][n-1]=t[1][n-1]+x2;  
       for(int i=n-2;i>=0;i--){  
           dp[0][i]=t[0][i];  
           dp[0][i]+=min(dp[0][i+1],trans[0][i]+dp[1][i+1]);  
           dp[1][i]=t[1][i];  
           dp[1][i]+=min(dp[1][i+1],trans[1][i]+dp[0][i+1]);  
       }  
       int ans=min(e1+dp[0][0],e2+dp[1][0]);  
       cout<<ans;  
    
    return 0;
 }
 