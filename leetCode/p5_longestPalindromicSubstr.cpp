

class Solution {
public:
    string longestPalindrome(string s) {
        int left=0, right=1, resStart=0, resLen=1, leng = s.size();
        if (leng <=1) return s;
        for(int mid=0; mid<leng;){
            left = right = mid;
            while(right<leng && s[right] == s[right+1]) right++;
            mid = right+1;
            while(left>0 && right<leng && s[left-1]==s[right+1]){ left--; right++;}
            if ((right-left+1) > resLen){ resStart = left; resLen=right-left+1; }
        }
        return s.substr(resStart,resLen);
    }
};