class Solution {
public:
    bool isPalindrome(string s) {
        int j = s.length()-1,i=0;
        while(i<=j){
            while(i<j&&!isalpha(s[i])&&!isdigit(s[i]))i++;    //can be done by while(i<j&&!isalnum(s[i]))i++;  <- Credit @bhawan0407 for this
            while(i<j&&!isalpha(s[j])&&!isdigit(s[j]))j--;
            if(tolower(s[i])==tolower(s[j]))i++,j--;
            else return false;
        }
        return true;
    }
};