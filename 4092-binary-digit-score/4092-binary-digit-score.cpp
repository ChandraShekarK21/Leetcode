class Solution {
public:
    int calculateScore(int a, int b) {
        string s1="";
        string s2="";
        while(a>0){
            s1+=(a%2)+'0';
            a/=2;
        }  
        while(b>0){
            s2+=(b%2)+'0';
            b/=2;
        }
        int s1_count1=0,s2_count1=0;
        for(char c:s1){
            if(c=='1'){
                s1_count1++;
            }
        }
        for(char c:s2){
            if(c=='1')s2_count1++;
        }
        if(s1_count1>=s2_count1)return s1_count1*s2_count1;
        return s2_count1/s1_count1;
    }
};