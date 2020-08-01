class Solution {
public:
    bool detectCapitalUse(string word) {
        bool flag = true;
        if( !isupper( word[0] ) ){
            for (int i = 1; i < word.length() ; i++)
            {
                if( isupper(word[i]) ) {
                    flag = false;
                    break;
                }
            }
        }else{
            if( isupper( word[1] ) ){
                for (int i = 2; i < word.length(); i++){
                    if( islower( word[i] ) ){
                        flag = false;
                        break;
                    }
                }
            }else{
                for (int i = 1; i < word.length(); i++){
                    if( isupper( word[i]) ){
                        flag = false;
                        break;
                    }
                }
            }
        }
        return flag;  
    }
};
