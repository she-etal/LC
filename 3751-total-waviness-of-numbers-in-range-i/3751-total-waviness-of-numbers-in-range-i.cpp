class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans=0;
        for(int num=num1; num<=num2; num++){
            vector<int> digit;
            int n=num;
            while(n){                
                digit.push_back(n%10);
                n /= 10;
            }
            reverse(digit.begin(), digit.end());
            for(int i=1; i<digit.size()-1; i++){                
                if(digit[i]>digit[i-1] and digit[i]>digit[i+1])
                ans++;
                else if(digit[i]<digit[i-1] and digit[i]<digit[i+1])
                ans++;
            }
        }
        return ans;
    }
};