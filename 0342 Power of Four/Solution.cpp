class Solution {
public:
    bool isPowerOfFour(int num) {
        if( num == 0) return false;
        
        double i = log(num)/log(4);
        
        return i == trunc(i);   
    }
};